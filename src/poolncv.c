/*  impl.c.poolncv
 *
 *                   NULL POOL COVERAGE TEST
 *
 *  $HopeName: !poolncv.c(MMdevel_sw_eq.2) $
 *
 *  Copyright (C) 1995 Harlequin Group, all rights reserved
 *
 */


#include "mpm.h"
#include "pooln.h"
#include "testlib.h"
#include <stdio.h>

int
main(void)
{
  Bool eflag = FALSE;
  Space space;
  Pool pool;
  Res res;
  Addr p;

  die(SpaceCreate(&space, (Addr)0, (Size)0), "SpaceCreate");

  die(PoolCreate(&pool, PoolPrefDefault(), PoolClassN(), space),
      "PoolNCreate");
  res = PoolAlloc(&p, pool, 1);
  if(res == ResOK) {
    fprintf(stderr,
            "Error:  Unexpectedly succeeded in"
            "allocating block from PoolN\n");
    eflag = TRUE;
  }
  PoolDestroy(pool);
  SpaceDestroy(space);
  if(eflag) {
    fprintf(stderr, "Conclusion:  Defects found.\n");
  } else {
    fprintf(stderr, "Conclusion:  Failed to find any defects.\n");
  }
  return 0;
}



