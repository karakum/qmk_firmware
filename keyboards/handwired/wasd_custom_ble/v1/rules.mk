# it should exist either in <this_dir>/ld/
MCU_LDSCRIPT = nrf52840
MCU_SERIES = NRF52840
NRFSDK_ROOT := $(NRFSDK15_ROOT) #Path to nRF SDK v15.0.0

NRFCFLAGS += -DBOOTLOADER_METHOD_ADAFUIT_UF2
NRFCFLAGS += -DNRF_LOG_BACKEND_UART_TX_PIN=38
NRFCFLAGS += -DENABLE_STARTUP_ADV_LIST
NRFCFLAGS += -DUSE_BATTERY_CHARGED_STATE_PIN=CHARGED
NRFCFLAGS += -DUSE_BATTERY_PIN=NRF_SAADC_INPUT_AIN7
NRFCFLAGS += -DBATTERY_R1=18020
NRFCFLAGS += -DBATTERY_R2=13734
NRFCFLAGS += -DBATTERY_VMAX=4130
NRFCFLAGS += -DBATTERY_VMIN=2550
