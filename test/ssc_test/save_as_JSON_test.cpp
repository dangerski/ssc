#include <string>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include "../ssc/vartab.h"
#include "json/json.h" // Jsoncpp
#include "../rapidjson/document.h"
#include "../rapidjson/istreamwrapper.h"

static const char* SSCDIR = std::getenv("SSCDIR");

char inputs_as_JSON[256] = {};
int nj1 = sprintf(inputs_as_JSON, "%s/test/input_json/pvwatts_merchantplant.json", SSCDIR);
char JSON_for_PySAM_PVWatts[256] = {};
int nj2 = sprintf(JSON_for_PySAM_PVWatts, "%s/test/input_json/pvwattsv7.json", SSCDIR);
char JSON_for_PySAM_Grid[256] = {};
int nj3 = sprintf(JSON_for_PySAM_Grid, "%s/test/input_json/grid.json", SSCDIR);
char JSON_for_PySAM_MerchantPlant[256] = {};
int nj4 = sprintf(JSON_for_PySAM_MerchantPlant, "%s/test/input_json/merchantplant.json", SSCDIR);

char inputs_as_JSON1[256] = {};
int np1 = sprintf(inputs_as_JSON1, "%s/test/input_json/pvwatts_merchantplant.json", SSCDIR);
char inputs_as_JSON2[256] = {};
int np2 = sprintf(inputs_as_JSON2, "%s/test/input_json/PV_Batt_MP.json", SSCDIR);
char inputs_as_JSON3[256] = {};
int np3 = sprintf(inputs_as_JSON3, "%s/test/input_json/PT_MP.json", SSCDIR);
char inputs_as_JSON4[256] = {};
int np4 = sprintf(inputs_as_JSON4, "%s/test/input_json/Trough_MP.json", SSCDIR);



TEST(save_as_JSON_test, pvwatts_mechant_plant_read_file_to_string) {
    std::ifstream test(inputs_as_JSON);
    std::string str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    EXPECT_EQ(str.length(), 12263249);
}

TEST(save_as_JSON_test_parse, pvwatts_mechant_plant_jsoncpp_parse_file) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream test(inputs_as_JSON, std::ifstream::binary);
    bool parsingSuccessful = reader.parse(test, root, false);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages()
            << "\n";
    }
    EXPECT_TRUE(parsingSuccessful);
}

TEST(save_as_JSON_test_parse, pvwatts_mechant_plant_rapidjson_parse_file) {
    std::ifstream test(inputs_as_JSON, std::ifstream::binary);
    rapidjson::Document document;
    rapidjson::IStreamWrapper isw(test);
    document.ParseStream(isw);
    if (document.HasParseError())
    {
        // report to the user the failure and their locations in the document.
        std::cout << document.GetParseError()
            << "\n";
    }
    EXPECT_TRUE(!document.HasParseError());
}
TEST(save_as_JSON_test_parse, pv_batt_mechant_plant_jsoncpp_parse_file) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream test(inputs_as_JSON2, std::ifstream::binary);
    bool parsingSuccessful = reader.parse(test, root, false);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages()
            << "\n";
    }
    EXPECT_TRUE(parsingSuccessful);
}

TEST(save_as_JSON_test_parse, pv_batt_mechant_plant_rapidjson_parse_file) {
    std::ifstream test(inputs_as_JSON2, std::ifstream::binary);
    rapidjson::Document document;
    rapidjson::IStreamWrapper isw(test);
    document.ParseStream(isw);
    if (document.HasParseError())
    {
        // report to the user the failure and their locations in the document.
        std::cout << document.GetParseError()
            << "\n";
    }
    EXPECT_TRUE(!document.HasParseError());
}
TEST(save_as_JSON_test_parse, pt_mechant_plant_jsoncpp_parse_file) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream test(inputs_as_JSON3, std::ifstream::binary);
    bool parsingSuccessful = reader.parse(test, root, false);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages()
            << "\n";
    }
    EXPECT_TRUE(parsingSuccessful);
}

TEST(save_as_JSON_test_parse, pt_mechant_plant_rapidjson_parse_file) {
    std::ifstream test(inputs_as_JSON3, std::ifstream::binary);
    rapidjson::Document document;
    rapidjson::IStreamWrapper isw(test);
    document.ParseStream(isw);
    if (document.HasParseError())
    {
        // report to the user the failure and their locations in the document.
        std::cout << document.GetParseError()
            << "\n";
    }
    EXPECT_TRUE(!document.HasParseError());
}
TEST(save_as_JSON_test_parse, trough_mechant_plant_jsoncpp_parse_file) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream test(inputs_as_JSON4, std::ifstream::binary);
    bool parsingSuccessful = reader.parse(test, root, false);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << reader.getFormatedErrorMessages()
            << "\n";
    }
    EXPECT_TRUE(parsingSuccessful);
}

TEST(save_as_JSON_test_parse, trough_mechant_plant_rapidjson_parse_file) {
    std::ifstream test(inputs_as_JSON4, std::ifstream::binary);
    rapidjson::Document document;
    rapidjson::IStreamWrapper isw(test);
    document.ParseStream(isw);
    if (document.HasParseError())
    {
        // report to the user the failure and their locations in the document.
        std::cout << document.GetParseError()
            << "\n";
    }
    EXPECT_TRUE(!document.HasParseError());
}




TEST(save_as_JSON_test_run, pvwatts_mechant_plant_jsoncpp_read_file_to_ssc_var_table) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto vt = json_to_ssc_data(json_str.c_str());
    std::string str(ssc_data_first(vt));
    EXPECT_EQ(str, "debt_option");
}

TEST(save_as_JSON_test_run, pvwatts_mechant_plant_rapidjson_read_file_to_ssc_var_table) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto vt = rapidjson_to_ssc_data(json_str.c_str());
    std::string str(ssc_data_first(vt));
    EXPECT_EQ(str, "pbi_fed_for_ds"); // differenct order
}


TEST(save_as_JSON_test_run, pvwatts_mechant_plant_jsoncpp_read_file_run_pvwatts) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = json_to_ssc_data(json_str.c_str());
    auto mod = ssc_module_create("pvwattsv7");
    ssc_module_exec_set_print(0);
    bool success = ssc_module_exec(mod, data);
    EXPECT_TRUE(success);
    ssc_number_t annual_energy;
    ssc_data_get_number(data, "annual_energy", &annual_energy);
    EXPECT_NEAR(annual_energy, 87966056, 87966056/1e6);
}

TEST(save_as_JSON_test_run, pvwatts_mechant_plant_rapidjson_read_file_run_pvwatts) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = rapidjson_to_ssc_data(json_str.c_str());
    auto mod = ssc_module_create("pvwattsv7");
    ssc_module_exec_set_print(0);
    bool success = ssc_module_exec(mod, data);
    EXPECT_TRUE(success);
    ssc_number_t annual_energy;
    ssc_data_get_number(data, "annual_energy", &annual_energy);
    EXPECT_NEAR(annual_energy, 87966056, 87966056 / 1e6);
}


TEST(save_as_JSON_test_run, pvwatts_mechant_plant_jsoncpp) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = json_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("pvwattsv7");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -60929408, fabs(60929408) / 1e6);
}

TEST(save_as_JSON_test_run, pvwatts_mechant_plant_rapidjson) {
    std::ifstream test(inputs_as_JSON);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = rapidjson_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("pvwattsv7");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -60929408, fabs(60929408) / 1e6);
}

TEST(save_as_JSON_test_run, pv_batt_mechant_plant_jsoncpp) {
    std::ifstream test(inputs_as_JSON2);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = json_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("pvsamv1");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -62278740, fabs(62278740) / 1e6);
}

TEST(save_as_JSON_test_run, pv_batt_mechant_plant_rapidjson) {
    std::ifstream test(inputs_as_JSON2);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = rapidjson_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("pvsamv1");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -62278740, fabs(62278740) / 1e6);
}

TEST(save_as_JSON_test_run, pt_mechant_plant_jsoncpp) {
    std::ifstream test(inputs_as_JSON3);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = json_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("tcsmolten_salt");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -591543354, fabs(591543354) / 1e8);
}

TEST(save_as_JSON_test_run, pt_mechant_plant_rapidjson) {
    std::ifstream test(inputs_as_JSON3);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = rapidjson_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("tcsmolten_salt");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -591543354, fabs(591543354) / 1e8);
}


TEST(save_as_JSON_test_run, ptrough_mechant_plant_jsoncpp) {
    std::ifstream test(inputs_as_JSON4);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = json_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("trough_physical");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -501734880, fabs(501734880) / 1e8);
}

TEST(save_as_JSON_test_run, ptrough_mechant_plant_rapidjson) {
    std::ifstream test(inputs_as_JSON4);
    std::string json_str((std::istreambuf_iterator<char>(test)), std::istreambuf_iterator<char>());
    auto data = rapidjson_to_ssc_data(json_str.c_str());
    ssc_module_exec_set_print(0);
    auto mod_pv = ssc_module_create("trough_physical");
    bool success = ssc_module_exec(mod_pv, data);
    EXPECT_TRUE(success);
    auto mod_grid = ssc_module_create("grid");
    success = ssc_module_exec(mod_grid, data);
    EXPECT_TRUE(success);
    auto mod_mp = ssc_module_create("merchantplant");
    success = ssc_module_exec(mod_mp, data);
    EXPECT_TRUE(success);
    ssc_number_t npv;
    ssc_data_get_number(data, "project_return_aftertax_npv", &npv);
    EXPECT_NEAR(npv, -501734880, fabs(501734880) / 1e8);
}
