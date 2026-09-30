/*
This file is part of Kotatogram Desktop,
part of the Telegram Desktop project.

For license and copyright information please follow this link:
https://github.com/kotatogram/kotatogram-desktop/blob/master/LEGAL
*/
#include "boxes/news_feed_edit_box.h"

#include "boxes/peer_list_box.h"
#include "boxes/peer_list_controllers.h"
#include "data/data_channel.h"
#include "data/data_chat_filters.h"
#include "data/data_peer.h"
#include "data/data_session.h"
#include "history/history.h"
#include "kotato/kotato_lang.h"
#include "lang/lang_keys.h"
#include "main/main_session.h"
#include "styles/style_boxes.h"
#include "window/window_session_controller.h"

namespace {

class NewsFeedChannelsController final : public ChatsListBoxController {
public:
	NewsFeedChannelsController(
		not_null<Main::Session*> session,
		base::flat_set<PeerId> excluded)
	: ChatsListBoxController(session)
	, _excluded(std::move(excluded)) {
	}

	void prepareViewHook() override {
		delegate()->peerListSetTitle(
			rpl::single(ktr("ktg_news_feed_edit_title")));
		setDescriptionText(ktr("ktg_news_feed_edit_about"));
	}

	std::unique_ptr<Row> createRow(not_null<History*> history) override {
		const auto peer = history->peer;
		const auto channel = peer->asChannel();
		if (!channel || !channel->isBroadcast()) {
			return nullptr;
		}
		auto row = std::make_unique<Row>(history);
		const auto included = !_excluded.contains(peer->id);
		row->setChecked(
			true,
			st::defaultPeerListItem.checkbox,
			anim::type::instant,
			[] {});
		if (!included) {
			row->setChecked(
				false,
				st::defaultPeerListItem.checkbox,
				anim::type::instant,
				[] {});
		}
		return row;
	}

	void rowClicked(not_null<PeerListRow*> row) override {
		delegate()->peerListSetRowChecked(row, !row->checked());
	}

private:
	base::flat_set<PeerId> _excluded;

};

} // namespace

void EditNewsFeedFilter(not_null<Window::SessionController*> controller) {
	const auto session = &controller->session();
	const auto filters = &session->data().chatsFilters();
	const auto &list = filters->list();
	const auto i = ranges::find(list, kNewsFeedFilterId, &Data::ChatFilter::id);
	if (i == end(list)) {
		// The tab was hidden while the box was open, just show it again.
		filters->setNewsFeedEnabled(true);
		return;
	}
	auto excluded = base::flat_set<PeerId>();
	for (const auto &history : i->never()) {
		excluded.emplace(history->peer->id);
	}
	auto chatController = std::make_unique<NewsFeedChannelsController>(
		session,
		std::move(excluded));
	const auto raw = chatController.get();
	const auto box = Box<PeerListBox>(
		std::move(chatController),
		[=](not_null<PeerListBox*> inner) {
			inner->addButton(tr::lng_settings_save(), [=] {
				auto never = base::flat_set<not_null<History*>>();
				const auto count = raw->delegate()->peerListFullRowsCount();
				for (auto j = 0; j != count; ++j) {
					const auto row = raw->delegate()->peerListRowAt(j);
					const auto peer = row->peer();
					const auto channel = peer->asChannel();
					if (channel && channel->isBroadcast() && !row->checked()) {
						never.emplace(session->data().history(peer->id));
					}
				}
				filters->setNewsFeedFilter(Data::ChatFilter(
					kNewsFeedFilterId,
					Data::ChatFilterTitle(),
					QString(),
					std::nullopt,
					Data::ChatFilter::Flag::Channels,
					{},
					{},
					std::move(never)));
				inner->closeBox();
			});
			inner->addButton(tr::lng_cancel(), [=] {
				inner->closeBox();
			});
		});
	controller->show(std::move(box));
}