typedef union _POP_FX_DEVICE_STATUS
{
  union
  {
    /* 0x0000 */ long Value;
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long SystemTransition : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long PepD0Notify : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long IdleTimerOn : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long IgnoreIdleTimeout : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long IrpInUse : 1; /* bit position: 4 */
      /* 0x0000 */ unsigned long IrpPending : 1; /* bit position: 5 */
      /* 0x0000 */ unsigned long DPNRDeviceNotified : 1; /* bit position: 6 */
      /* 0x0000 */ unsigned long DPNRReceivedFromPep : 1; /* bit position: 7 */
      /* 0x0000 */ unsigned long Reserved : 24; /* bit position: 8 */
    }; /* bitfield */
  }; /* size: 0x0004 */
} POP_FX_DEVICE_STATUS, *PPOP_FX_DEVICE_STATUS; /* size: 0x0004 */

