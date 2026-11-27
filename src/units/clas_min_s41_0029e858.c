#include "../common.h"
typedef struct { char p[24]; float x, y, ylo, yhi, xlo, xhi, vx, vy; } M;
// MATCH func_0029E858
void clas_min_0029e858(M *o) {
  float t;
  if (o->vx != 0.0f) {
    t = o->x + o->vx; o->x = t;
    if (t <= o->xlo) o->x = t + (o->xhi - o->xlo);
    else if (o->xhi <= t) o->x = t + (o->xlo - o->xhi);
  }
  if (o->vy != 0.0f) {
    t = o->y + o->vy; o->y = t;
    if (t < o->ylo) o->y = t + (o->yhi - o->ylo);
    else if (o->yhi < t) o->y = t + (o->ylo - o->yhi);
  }
}
