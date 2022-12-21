#ifndef COMPONENT_H
#define COMPONENT_H

#define RENDER_LOCK 1
#define POSITION_LOCK 2
#define COLLIDER_LOCK 4
#define CONTROLLER_LOCK 8

#define HAS_COMPONENTS(mgr, id, components) \
  (((mgr)->entity_locks[id] & (components)) == (components))

#endif
