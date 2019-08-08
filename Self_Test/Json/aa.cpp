#include "json.h"
#include <stdio.h>
#include <iostream>
#include <string>

static const char* const KEY_CATEGORY = "category";
static const char* const KEY_PARAMETER = "parameter";
static const char* const KEY_VALUE = "value";
static const char* const KEY_CATEGORY_SERVICE = "Service";	// category is Service


std::string body =
        "["
        "{\"category\":\"MOF\",         \"parameter\":\"USER.id\",          \"value\":\"1234567890\"},"
        "{\"category\":\"MOF\",         \"parameter\":\"USER.pw\",          \"value\":\"0987654321\"},"
        "{\"category\":\"Common\",      \"parameter\":\"AuthSMSNum\",       \"value\":\"11111\"},"
        "{\"category\":\"Common\",      \"parameter\":\"InCallNum\",        \"value\":\"22222\"},"
        "{\"category\":\"Common\",      \"parameter\":\"SOSCallNum\",       \"value\":\"33333\"},"
        "{\"category\":\"Common\",      \"parameter\":\"SMSSenderNum\",     \"value\":\"44444\"},"
        "{\"category\":\"Common\",      \"parameter\":\"SMSMailbox\",       \"value\":\"127.0.0.1\"},"
        "{\"category\":\"Common\",      \"parameter\":\"ADC.host\",         \"value\":\"https://a.b.com\"},"
        "{\"category\":\"Common\",      \"parameter\":\"ADC.port\",         \"value\":\"443\"},"
        "{\"category\":\"Common\",      \"parameter\":\"DTCCallNum\",       \"value\":\"55555\"},"
        "{\"category\":\"Common\",      \"parameter\":\"AcnOutcallNum\",    \"value\":\"66666\"},"
        "{\"category\":\"Common\",      \"parameter\":\"DTCOutcallNum\",    \"value\":\"77777\"},"
        "{\"category\":\"Common\",      \"parameter\":\"InfoOutcallNum\",   \"value\":\"88888\"},"
        "{\"category\":\"Common\",      \"parameter\":\"DAACallNum\",       \"value\":\"99999\"},"
        "{\"category\":\"Vehicle\",     \"parameter\":\"VehicleVin\",       \"value\":\"ABCDEF\"},"
        "{\"category\":\"DTC\",         \"parameter\":\"EMS\",              \"value\":\"1\"},"
        "{\"category\":\"CAN ID\",      \"parameter\":\"EMS\",              \"value\":\"07e0/07e8\"},"
        "{\"category\":\"CAN ID\",      \"parameter\":\"TCU\",              \"value\":\"07e1/07e9\"},"
        "{\"category\":\"Maintenance\", \"parameter\":\"0001\",             \"value\":\"15000\"},"
        "{\"category\":\"Service\",     \"parameter\":\"LOS\",              \"value\":\"1\"},"
        "{\"category\":\"Service\",     \"parameter\":\"POI\",              \"value\":\"1\"},"
        "{\"category\":\"Service\",     \"parameter\":\"S2C\",              \"value\":\"1\"}"
        "]";
bool kikiki(Json::Value &bb){
    printf("\n\n\n");
    Json::Value aa;
    Json::Value cc;
    for(auto &it : bb){
        printf("%s\n",it[KEY_CATEGORY].asString().c_str());
        printf("%s\n",it[KEY_PARAMETER].asString().c_str());
        printf("%s\n",it[KEY_VALUE].asString().c_str());
        // Convert CAN ECU ID to lower
            aa[KEY_CATEGORY] = it[KEY_CATEGORY];
            aa[KEY_PARAMETER] = it[KEY_PARAMETER];
            aa[KEY_VALUE] = it[KEY_VALUE];
            cc[""]=aa;

    }
}

bool kakaka(Json::Value &bb){
    int zz;
    Json::Value aa;
    Json::Value cc;
    for(auto &it : bb){
        printf("%s\n",it[KEY_CATEGORY].asString().c_str());
        // Convert CAN ECU ID to lower
        if (it[KEY_CATEGORY].asString() == KEY_CATEGORY_SERVICE){
            aa[KEY_CATEGORY] = it[KEY_CATEGORY];
            aa[KEY_PARAMETER] = it[KEY_PARAMETER];
            aa[KEY_VALUE] = it[KEY_VALUE];
            cc.append(aa);
        }
    }
    bb=cc;
}

int main(void){
    Json::Value root;
    Json::Reader reader;
    bool parsed;
    parsed = reader.parse(body, root);

    kakaka(root);
    kikiki(root);
    return 0;
}
