
// If you want to use a set of functions to handle SD/SPIFFS/HTTP,
//  please include <SD.h>,<SPIFFS.h>,<HTTPClient.h> before <M5GFX.h>
// #include <SD.h>
// #include <SPIFFS.h>
// #include <HTTPClient.h>

#include "lgfx/v1/panel/Panel_SSD1306.hpp"
#include "M5GFX.h"

#define GENERIC_SSD1306_SDA 21
#define GENERIC_SSD1306_SCL 22
#define GENERIC_SSD1306_PORT 0
#define GENERIC_SSD1306_ADDR 0x3C
#define GENERIC_SSD1306_FREQ 400000

class M5_GENERIC_SSD1306  : public M5GFX
{
  lgfx::Bus_I2C::config_t _bus_cfg;

public:

  struct config_t
  {
    uint8_t  pin_sda   = GENERIC_SSD1306_SDA;
    uint8_t  pin_scl   = GENERIC_SSD1306_SCL;
    uint8_t  i2c_addr  = GENERIC_SSD1306_ADDR;
    int8_t   i2c_port  = GENERIC_SSD1306_PORT;
    uint32_t i2c_freq  = GENERIC_SSD1306_FREQ;
  };


  config_t config(void) const { return config_t(); }

  M5_GENERIC_SSD1306 (const config_t &cfg)
  {
    uint8_t pin_sda = cfg.pin_sda < GPIO_NUM_MAX ? cfg.pin_sda : GENERIC_SSD1306_SDA;
    uint8_t pin_scl = cfg.pin_scl < GPIO_NUM_MAX ? cfg.pin_scl : GENERIC_SSD1306_SCL;
    setup(pin_sda, pin_scl, cfg.i2c_freq, cfg.i2c_port, cfg.i2c_addr);
  }

  M5_GENERIC_SSD1306 (uint8_t pin_sda = GENERIC_SSD1306_SDA, uint8_t pin_scl = GENERIC_SSD1306_SCL, uint32_t i2c_freq = GENERIC_SSD1306_FREQ, int8_t i2c_port = -1, uint8_t i2c_addr = GENERIC_SSD1306_ADDR)
  {
    setup(pin_sda, pin_scl, i2c_freq, i2c_port, i2c_addr);
    
  }

  using lgfx::LGFX_Device::init;
  bool init(uint8_t pin_sda, uint8_t pin_scl, uint32_t i2c_freq = GENERIC_SSD1306_FREQ, int8_t i2c_port = -1, uint8_t i2c_addr = GENERIC_SSD1306_ADDR)
  {
    setup(pin_sda, pin_scl, i2c_freq, i2c_port, i2c_addr);
    return init();
  }


  void setup(uint8_t pin_sda = GENERIC_SSD1306_SDA, uint8_t pin_scl = GENERIC_SSD1306_SCL, uint32_t i2c_freq = GENERIC_SSD1306_FREQ, int8_t i2c_port = -1, uint8_t i2c_addr = GENERIC_SSD1306_ADDR)
  {
    //_board = lgfx::board_t::board_M5UnitGLASS;
    if (i2c_port < 0)
    {
      i2c_port = 0;


#ifdef _M5EPD_H_
      if ((pin_sda == 25 && pin_scl == 32)  /// M5Paper
      {
        i2c_port = 1
      }
#endif
    }

    {

      _bus_cfg.freq_write = i2c_freq;
      _bus_cfg.freq_read =i2c_freq;
      _bus_cfg.pin_scl = pin_scl;
      _bus_cfg.pin_sda = pin_sda;
      _bus_cfg.i2c_port = i2c_port;
      _bus_cfg.i2c_addr = i2c_addr;


      _bus_cfg.prefix_len = 1;

    }
  }

  bool init_impl(bool use_reset, bool use_clear)
  {

    if (_panel_last.get() != nullptr) {

      return true;
    }

    auto p = new lgfx::Panel_SSD1306();
    auto b = new lgfx::Bus_I2C();
    b->config(_bus_cfg);

    {

      p->bus(b);
      auto cfg = p->config();
      cfg.offset_rotation = 3;
      p->config(cfg);
    }



    setPanel(p);

    if (lgfx::LGFX_Device::init_impl(use_reset, use_clear)) {

      _panel_last.reset(p);
      _bus_last.reset(b);


      return true;
    }

    setPanel(nullptr);

    delete p;
    delete b;
    return false;

  }


/*
  uint8_t getKey(uint_fast8_t key)
  {
    auto p = (lgfx::Panel_SSD1306 *)_panel_last.get();
    return (p == nullptr) ? 1 : p->getKey(key);
  }

  uint8_t getFirmwareVersion(void)
  {
    auto p = (lgfx::Panel_SSD1306 *)_panel_last.get();
    return (p == nullptr) ? 1 : p->getFirmwareVersion();
  }

  void setBuzzer(uint16_t freq, uint8_t duty) {
    auto p = (lgfx::Panel_SSD1306 *)_panel_last.get();
    p->setBuzzer(freq, duty);
  }

  void setBuzzerEnable(bool enable = true) {
    auto p = (lgfx::Panel_SSD1306 *)_panel_last.get();
    p->setBuzzerEnable(enable);
  }
*/

};
