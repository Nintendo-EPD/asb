/*I believe that this function is in charge of loading and parsing data from the asb/ainb files*/

undefined8 FUN_710074c860(byte **param_1,byte **param_2)

{
  uint uVar1;
  long lVar2;
  byte *pbVar3;
  int iVar4;
  ulong uVar5; /* uVar5 is the current position in pbVar3 while reading; May also be amount of bytes read to figure out data types */
  int iVar6;
  uint uVar7;
  ulong uVar8;
  byte *__dest;
  pbVar3 = *param_2; /* pbVar3 is the file reader/array of bytes contained in the file */
  if ((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) {
    LAB_710074ca50:
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    do {
      if (uVar5 == 0x400000) goto LAB_710074ca50; // Resets uVar5 to 0
      if (pbVar3[uVar5 + 1] == 0) {
        uVar5 = uVar5 + 1;
        break;
      }
      lVar2 = uVar5 + 2;
      uVar5 = uVar5 + 2;
    } while (pbVar3[lVar2] != 0);
    uVar5 = uVar5 & 0xffffffff; // Ensures uVar5 does not surpass maximum size
  }
  iVar4 = -1;
  do {
    uVar8 = uVar5 - 1;
    if ((long)uVar5 < 1) goto LAB_710074c8c8;
    uVar5 = uVar8;
  } while (pbVar3[uVar8 & 0xffffffff] != 0x5c);
  iVar4 = (int)uVar8;
LAB_710074c8c8:
  if ((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) {
LAB_710074ca58:
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    do {
      if (uVar5 == 0x400000) goto LAB_710074ca58;
      if (pbVar3[uVar5 + 1] == 0) {
        uVar5 = uVar5 + 1;
        break;
      }
      lVar2 = uVar5 + 2;
      uVar5 = uVar5 + 2;
    } while (pbVar3[lVar2] != 0);
    uVar5 = uVar5 & 0xffffffff;
  }
  iVar6 = -1;
  do {
    uVar8 = uVar5 - 1;
    if ((long)uVar5 < 1) goto LAB_710074c920;
    uVar5 = uVar8;
  } while (pbVar3[uVar8 & 0xffffffff] != 0x2f);
  iVar6 = (int)uVar8;
LAB_710074c920:
  if (iVar4 <= iVar6) {
    iVar4 = iVar6;
  }
  uVar1 = 0;
  if (-1 < iVar4) {
    uVar1 = iVar4 + 1;
  }
  if ((pbVar3 == (byte *)0x0) || (*pbVar3 == 0)) {
LAB_710074ca60:
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
    do {
      if (uVar5 == 0x400000) goto LAB_710074ca60;
      if (pbVar3[uVar5 + 1] == 0) {
        uVar5 = uVar5 + 1;
        break;
      }
      lVar2 = uVar5 + 2;
      uVar5 = uVar5 + 2;
    } while (pbVar3[lVar2] != 0);
    uVar5 = uVar5 & 0xffffffff;
  }
  do {
    uVar8 = uVar5 - 1;
    if ((long)uVar5 < 1) {
      if (pbVar3 == (byte *)0x0) goto LAB_710074ca70;
      goto LAB_710074c994;
    }
    uVar5 = uVar8;
  } while (pbVar3[uVar8 & 0xffffffff] != 0x2e);
  uVar7 = (uint)uVar8;
  uVar5 = (ulong)(uVar7 & ((int)uVar7 >> 0x1f ^ 0xffffffffU));
  if (((int)uVar7 < 0) && (pbVar3 != (byte *)0x0)) {
LAB_710074c994:
    uVar5 = (ulong)*pbVar3;
    if (*pbVar3 != 0) {
      uVar5 = 0;
      do {
        if (uVar5 == 0x400000) goto LAB_710074ca70;
        if (pbVar3[uVar5 + 1] == 0) {
          uVar5 = uVar5 + 1;
          break;
        }
        lVar2 = uVar5 + 2;
        uVar5 = uVar5 + 2;
      } while (pbVar3[lVar2] != 0);
    }
  }
LAB_710074c9c8:
  if ((-1 < (int)uVar1) && ((int)uVar1 < 0x400001)) {
    if ((int)uVar1 < 1) {
LAB_710074cabc:
      pbVar3 = pbVar3 + (int)uVar1;
      goto LAB_710074c9d4;
    }
    if (*pbVar3 != 0) {
      uVar8 = 0;
      do {
        if ((ulong)uVar1 - 1 == uVar8) goto LAB_710074cabc;
        lVar2 = uVar8 + 1;
        uVar8 = uVar8 + 1;
      } while (pbVar3[lVar2] != 0);
      if (uVar1 <= uVar8) goto LAB_710074cabc;
    }
  }
  pbVar3 = &DAT_7103776e54;
LAB_710074c9d4:
  __dest = *param_1;
  if (__dest != pbVar3) {
    uVar1 = (int)uVar5 - uVar1;
    uVar5 = (ulong)uVar1;
    if ((int)uVar1 < 0) {
      if (pbVar3 == (byte *)0x0) {
LAB_710074ca68:
        uVar5 = 0;
      }
      else {
        uVar5 = (ulong)*pbVar3;
        if (*pbVar3 != 0) {
          uVar5 = 0;
          do {
            if (uVar5 == 0x400000) goto LAB_710074ca68;
            if (pbVar3[uVar5 + 1] == 0) {
              uVar5 = uVar5 + 1;
              break;
            }
            lVar2 = uVar5 + 2;
            uVar5 = uVar5 + 2;
          } while (pbVar3[lVar2] != 0);
        }
      }
    }
    iVar4 = (int)uVar5;
    if (*(int *)(param_1 + 1) <= (int)uVar5) {
      iVar4 = *(int *)(param_1 + 1) + -1;
    }
    memcpy(__dest,pbVar3,(long)iVar4);
    __dest[iVar4] = 0;
  }
  return 1;
LAB_710074ca70:
  uVar5 = 0;
  goto LAB_710074c9c8;
}

