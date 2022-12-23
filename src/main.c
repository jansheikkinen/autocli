// main.c

#include <unistd.h>
#include <time.h>
#include <locale.h>

#include "util/common.h"
#include "game/game.h"
#include "entity/player.h"
#include "entity/enemy.h"

struct Game game;

void init_screen(void) {
  setlocale(LC_ALL, "");
  initscr(); cbreak(); nodelay(stdscr, true); keypad(stdscr, true); noecho();
  curs_set(0); start_color();
}

void setup(void) {
  init_screen();

  struct Settings settings;
  init_default_settings(&settings);

  init_game(&game, settings);

  struct World* world = malloc(sizeof(*world));
  init_world(&game, world);

  game.world = world;

  init_player_entity(game.world->chunks[5]);

  init_enemy_entity(game.world->chunks[5], &(struct Vector){ 1, 2 });

  game.world->chunks[5]->position = (struct Vector){ 12, 12 };
}

static clock_t last_time, delta_time = 0;
static size_t ticks_passed, tick_timer = 0;

static int millis_sleep(long ms) {
  return nanosleep(&(struct timespec){ 0, ms * 10000000 }, NULL);
}

static void update_delta_time(void) {
  clock_t current_time = clock() * 1000 / CLOCKS_PER_SEC;
  delta_time = current_time - last_time;
  last_time = current_time;
}

static bool tick(void) {
  update_delta_time();
  tick_timer += delta_time;

  if(tick_timer >= TICK_LENGTH) {
    ticks_passed += 1;
    tick_timer -= TICK_LENGTH;

    return true;
  } else {
    millis_sleep(TICK_LENGTH);

    return false;
  }
}

static void print_debug_info(void) {
  char tick_str[40];
  snprintf(tick_str, 40, "ticks passed: %ld", ticks_passed);
  mvaddstr(2, 60, tick_str);

  snprintf(tick_str, 40, "delta time: %ld  ", delta_time);
  mvaddstr(3, 60, tick_str);
}

int main(void) {
  setup();

  while(1) {
    if(tick()) {
      clear();
      update_world(game.world);
      print_debug_info();
      refresh();
    }
  }
}
