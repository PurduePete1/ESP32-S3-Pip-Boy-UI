#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "esp_system.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "tft.h"  // Custom TFT Driver (ILI9341)

// Log Tag
static const char *TAG = "PIPBOY_UI";

// Function Prototypes
void draw_icon(int x, int y, const char *label);

// Tell C++ to use C-style linkage for ESP-IDF functions
extern "C" void app_main(void) {  
    ESP_LOGI(TAG, "Initializing TFT...");

    // Initialize TFT
    tft_init();
    tft_fill_screen(TFT_BLACK);
    tft_set_text_color(TFT_GREEN, TFT_BLACK);
    
    // Draw UI Icons
    draw_icon(30, 50, "GPS");
    draw_icon(120, 50, "SCAN");
    draw_icon(210, 50, "LOGS");
    draw_icon(120, 150, "SETTINGS");

    ESP_LOGI(TAG, "UI Loaded. Entering main loop...");
    
    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));  // Keep task alive
    }
}

// C++ Function for Drawing Icons
void draw_icon(int x, int y, const char *label) {
    tft_draw_rect(x, y, 60, 60, TFT_GREEN);  // Draw box
    tft_set_cursor(x + 10, y + 70);
    tft_print(label);
}
