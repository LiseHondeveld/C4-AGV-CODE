/*#include "agv_tof.h"

#define REG_IDENTIFICATION_MODEL_ID (0xC0)
#define REG_VHV_CONFIG_PAD_SCL_SDA_EXTSUP_HV (0x89)
#define REG_MSRC_CONFIG_CONTROL (0x60)
#define REG_FINAL_RANGE_CONFIG_MIN_COUNT_RATE_RTN_LIMIT (0x44)
#define REG_SYSTEM_SEQUENCE_CONFIG (0x01)
#define REG_DYNAMIC_SPAD_REF_EN_START_OFFSET (0x4F)
#define REG_DYNAMIC_SPAD_NUM_REQUESTED_REF_SPAD (0x4E)
#define REG_GLOBAL_CONFIG_REF_EN_START_SELECT (0xB6)
#define REG_SYSTEM_INTERRUPT_CONFIG_GPIO (0x0A)
#define REG_GPIO_HV_MUX_ACTIVE_HIGH (0x84)
#define REG_SYSTEM_INTERRUPT_CLEAR (0x0B)
#define REG_RESULT_INTERRUPT_STATUS (0x13)
#define REG_SYSRANGE_START (0x00)
#define REG_GLOBAL_CONFIG_SPAD_ENABLES_REF_0 (0xB0)
#define REG_RESULT_RANGE_STATUS (0x14)


#define TOF_DEFAULT_ADDR
#define TOF1_ADDR
#define TOF2_ADDR

#define TOF1_INT_BANK
#define TOF1_INT_PIN
#define TOF1_SHUT_BANK
#define TOF1_SHUT_PIN

#define TOF2_INT_BANK
#define TOF2_INT_PIN
#define TOF2_SHUT_BANK
#define TOF2_SHUT_PIN

static uint8_t tof1_stop_variable = 0;
static uint8_t tof2_stop_variable = 0;

/**
 * One time device initialization
 *//*

uint8_t tof_init_addr8(uint8_t addr8)
{
    if(!load_default_tuning_settings())
        return 1;
    if(!configure_interrupt())
        return 1;
    if(!set_sequence_steps_enabledRange(RANGE_SEQUENCE_STEP_DSS, RANGE_SEQUENCE_STEP_PRE_RANGE, RANGE_SEQUENCE_STEP_FINAL_RANGE))
}
uint8_t tof_data_init(uint8_t addr8, uint8_t &stop_variable)
{
        bool success = false;

    /* Set 2v8 mode *//*
    uint8_t vhv_config_scl_sda = 0;
    if (!i2c_read_addr8_register8_pointer8(addr8, REG_VHV_CONFIG_PAD_SCL_SDA_EXTSUP_HV, &vhv_config_scl_sda)) {
        return false;
    }
    vhv_config_scl_sda |= 0x01;
    if (!i2c_write_addr8_register8_data8(addr8, REG_VHV_CONFIG_PAD_SCL_SDA_EXTSUP_HV, vhv_config_scl_sda)) {
        return false;
    }

    /* Set I2C standard mode *//*
    success = i2c_write_addr8_register8_data8(addr8, 0x88, 0x00);

    success &= i2c_write_addr8_register8_data8(addr8, 0x80, 0x01);
    success &= i2c_write_addr8_register8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_register8_data8(addr8, 0x00, 0x00);
    success &= i2c_read_addr8_register8_pointer8(addr8, 0x91, &stop_variable);
    success &= i2c_write_addr8_register8_data8(addr8, 0x00, 0x01);
    success &= i2c_write_addr8_register8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_register8_data8(addr8, 0x80, 0x00);

    return success;
}

/**
 * Load tuning settings (same as default tuning settings provided by ST api code)
 *//*
static bool load_default_tuning_settings(uint8_t addr8)
{
    bool success = i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x00, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x09, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x10, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x11, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x24, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x25, 0xFF);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x75, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x4E, 0x2C);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x48, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x30, 0x20);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x30, 0x09);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x54, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x31, 0x04);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x32, 0x03);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x40, 0x83);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x46, 0x25);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x60, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x27, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x50, 0x06);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x51, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x52, 0x96);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x56, 0x08);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x57, 0x30);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x61, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x62, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x64, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x65, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x66, 0xA0);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x22, 0x32);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x47, 0x14);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x49, 0xFF);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x4A, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x7A, 0x0A);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x7B, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x78, 0x21);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x23, 0x34);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x42, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x44, 0xFF);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x45, 0x26);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x46, 0x05);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x40, 0x40);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x0E, 0x06);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x20, 0x1A);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x43, 0x40);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x34, 0x03);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x35, 0x44);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x31, 0x04);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x4B, 0x09);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x4C, 0x05);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x4D, 0x04);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x44, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x45, 0x20);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x47, 0x08);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x48, 0x28);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x67, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x70, 0x04);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x71, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x72, 0xFE);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x76, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x77, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x0D, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x80, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x01, 0xF8);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x8E, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x00, 0x01);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0xFF, 0x00);
    success &= i2c_write_addr8_pointer8_data8(addr8, 0x80, 0x00);

    return success;
}

static bool configure_interrupt(uint8_t addr8)
{
    /* Interrupt on new sample ready *//*$
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSTEM_INTERRUPT_CONFIG_GPIO, 0x04)) {
        return false;
    }

    /* Configure active low since the pin is pulled-up on most breakout boards *//*
    uint8_t gpio_hv_mux_active_high = 0;
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_GPIO_HV_MUX_ACTIVE_HIGH, &gpio_hv_mux_active_high)) {
        return false;
    }
    gpio_hv_mux_active_high &= ~0x10;
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_GPIO_HV_MUX_ACTIVE_HIGH, gpio_hv_mux_active_high)) {
        return false;
    }

    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSTEM_INTERRUPT_CLEAR, 0x01)) {
        return false;
    }
    return true;
}

//#define RANGE_SEQUENCE_STEP_TCC (0x10) /* Target CentreCheck */
//#define RANGE_SEQUENCE_STEP_MSRC (0x04) /* Minimum Signal Rate Check */
//#define RANGE_SEQUENCE_STEP_DSS (0x28) /* Dynamic SPAD selection */
//#define RANGE_SEQUENCE_STEP_PRE_RANGE (0x40)
//#define RANGE_SEQUENCE_STEP_FINAL_RANGE (0x80)

/**
 * Enable (or disable) specific steps in the sequence
 *//*
static bool set_sequence_steps_enabled(uint8_t addr8, uint8_t sequence_step)
{
    return i2c_write_addr8_pointer8_data8(addr8, REG_SYSTEM_SEQUENCE_CONFIG, sequence_step);
}


//vanaf hier temp
typedef enum
{
    CALIBRATION_TYPE_VHV,
    CALIBRATION_TYPE_PHASE
} calibration_type_t;

static bool perform_single_ref_calibration(addr8, calibration_type_t calib_type)
{
    uint8_t sysrange_start = 0;
    uint8_t sequence_config = 0;
    switch (calib_type)
    {
    case CALIBRATION_TYPE_VHV:
        sequence_config = 0x01;
        sysrange_start = 0x01 | 0x40;
        break;
    case CALIBRATION_TYPE_PHASE:
        sequence_config = 0x02;
        sysrange_start = 0x01 | 0x00;
        break;
    }
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSTEM_SEQUENCE_CONFIG, sequence_config)) {
        return false;
    }
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSRANGE_START, sysrange_start)) {
        return false;
    }
    /* Wait for interrupt *//*
    uint8_t interrupt_status = 0;
    bool success = false;
    do {
        success = i2c_read_addr8_data8(addr8, REG_RESULT_INTERRUPT_STATUS, &interrupt_status);
    } while (success && ((interrupt_status & 0x07) == 0));
    if (!success) {
        return false;
    }
    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSTEM_INTERRUPT_CLEAR, 0x01)) {
        return false;
    }

    if (!i2c_write_addr8_pointer8_data8(addr8, REG_SYSRANGE_START, 0x00)) {
        return false;
    }
    return true;
}

/**
 * Temperature calibration needs to be run again if the temperature changes by
 * more than 8 degrees according to the datasheet.
 *//*
static bool perform_ref_calibration(uint8_t addr8)
{
    if (!perform_single_ref_calibration(addr8, CALIBRATION_TYPE_VHV)) {
        return false;
    }
    if (!perform_single_ref_calibration(addr8, CALIBRATION_TYPE_PHASE)) {
        return false;
    }
    /* Restore sequence steps enabled *//*
    if (!set_sequence_steps_enabled(addr8, RANGE_SEQUENCE_STEP_DSS +
                                    RANGE_SEQUENCE_STEP_PRE_RANGE +
                                    RANGE_SEQUENCE_STEP_FINAL_RANGE)) {
        return false;
    }
    return true;
}

bool vl53l0x_init(uint8_t addr8)
{
    if (!device_is_booted()) {
        return false;
    }
    if (!data_init(add8)) {
        return false;
    }
    if (!static_init(addr8)) {
        return false;
    }
    if (!perform_ref_calibration(addr8)) {
        return false;
    }
    return true;
}
*/
