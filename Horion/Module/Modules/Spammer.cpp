#include "Spammer.h"
#include "../../../Utils/Utils.h"

Spammer::Spammer() : IModule(0, Category::MISC, "Spams a message in a specified delay") {
	registerIntSetting("delay", &this->delay, this->delay, 1, 10);
	registerIntSetting("length", &this->length, this->length, 1, 60);
	registerBoolSetting("bypass", &this->bypass, this->bypass);
}

Spammer::~Spammer() {
}

const char* Spammer::getModuleName() {
	return ("Spammer");
}

void Spammer::onTick(C_GameMode* gm) {
	Odelay++;
	if (Odelay > delay * 20) {
		C_TextPacket textPacket;
		textPacket.message.setText(bypass ? (message + " | " + Utils::randomString(length)) : message);
		textPacket.message.setText(bypass ? (message2 + " | " + Utils::randomString(length)) : message);
		textPacket.message.setText(bypass ? (message3 + " | " + Utils::randomString(length)) : message);
		textPacket.message.setText(bypass ? (message4 + " | " + Utils::randomString(length)) : message);
		textPacket.message.setText(bypass ? (message5 + " | " + Utils::randomString(length)) : message);
		textPacket.message.setText(bypass ? (message6 + " | " + Utils::randomString(length)) : message);
		textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
		textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
		g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
		Odelay = 0;
	}
}
