#include <SDL2/SDL.h>
#include <cstdint>
#include <iostream>

// Classe pour le CPU 6502
class CPU {
public:
    void step() {
        // Logique d'émulation du CPU
        std::cout << "CPU Step" << std::endl;
    }
};

// Classe pour le PPU (Picture Processing Unit)
class PPU {
public:
    void step() {
        // Logique d'émulation du PPU
        std::cout << "PPU Step" << std::endl;
    }

    uint32_t* get_screen() {
        static uint32_t screen[256 * 240] = {0}; // Exemple de framebuffer
        return screen;
    }
};

// Classe pour le bus mémoire
class Bus {
public:
    CPU cpu;
    PPU ppu;

    void write(uint16_t addr, uint8_t data) {
        // Logique d'écriture en mémoire
    }

    uint8_t read(uint16_t addr) {
        // Logique de lecture en mémoire
        return 0;
    }
};

// Fonction pour récupérer les entrées depuis le Pico
uint8_t get_pico_input() {
    // Exemple de code pour récupérer les entrées
    return 0;
}

// Fonction pour rendre le framebuffer
void render_frame(uint32_t* screen) {
    // Logique de rendu avec SDL
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(256, 240, 0, &window, &renderer);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 256, 240);

    SDL_UpdateTexture(texture, nullptr, screen, 256 * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(16); // 60 FPS
}

int main() {
    Bus bus;

    bool running = true;
    while (running) {
        bus.cpu.step();
        bus.ppu.step();

        uint8_t input_state = get_pico_input();
        // Gestion des entrées

        render_frame(bus.ppu.get_screen());
    }

    return 0;
}