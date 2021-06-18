#include <iostream>
//include the google test dependencies
#include <gtest/gtest.h>
#include "weatherstation.h"
#include "client.h"
#define private public


struct WeatherStationTest : public testing::Test {
    WeatherStation *server;
    Client *client1;

    void setUp() {
    server = new WeatherStation();
    client1 = new Client(*server);
    }
    void TearDown() {
    delete server;
    delete client1;
    }
};

TEST_F(WeatherStationTest, Add_client) {
  ASSERT_EQ(server->list_observer_.size(), 1);
}

TEST_F(WeatherStationTest, Set){
  server->SetState(23.5, 115.4, 263);

  ASSERT_EQ(server->temperature, 23.5);
  ASSERT_EQ(server->pressure, 115.4);
  ASSERT_EQ(server->humidity, 23.5);
}

TEST_F(WeatherStationTest, Remove_client ){
  server->Remove(client1);

  ASSERT_EQ(server->list_observer_.size(), 1);
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
