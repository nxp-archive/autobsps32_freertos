/******************************************************************************
* File:    vectors.h
*
* Purpose: Provide custom interrupt service routines for s32v234.
*
* NOTE: This vector table is a superset table, so interrupt sources might be
*       listed that are not available on the specific s32v234 device you are
*       using.
******************************************************************************/

#ifndef __VECTORS_H
#define __VECTORS_H     1

/* The kernel interrupts - in their CMSIS form. */
extern void SVC_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void );


/* Function prototype for default_isr in vectors.c */
void default_isr(void);


/* Interrupt Vector Table Function Pointers */
typedef void pointer(void);

extern void __startup(void);

extern unsigned long __BOOT_STACK_ADDRESS[];
extern void __iar_program_start(void);
                                            /* Address     Vector IRQ   Source module   Source description                               */
#define VECTOR_000      (pointer*)__BOOT_STACK_ADDRESS  /*              ARM core        Initial Stack Pointer                            */
#define VECTOR_001      __startup           /* 0x0000_0004 1 -          ARM core        Initial Program Counter                          */
#define VECTOR_002      default_isr         /* 0x0000_0008 2 -          ARM core        Non-maskable Interrupt (NMI)                     */
#define VECTOR_003      default_isr         /* 0x0000_000C 3 -          ARM core        Hard Fault                                       */
#define VECTOR_004      default_isr         /* 0x0000_0010 4 -          ARM core        MemManage Fault                                  */
#define VECTOR_005      default_isr         /* 0x0000_0014 5 -          ARM core        Bus Fault                                        */
#define VECTOR_006      default_isr         /* 0x0000_0018 6 -          ARM core        Usage Fault                                      */
#define VECTOR_007      default_isr         /* 0x0000_001C 7 -                                                                           */
#define VECTOR_008      default_isr         /* 0x0000_0020 8 -                                                                           */
#define VECTOR_009      default_isr         /* 0x0000_0024 9 -                                                                           */
#define VECTOR_010      default_isr         /* 0x0000_0028 10 -                                                                          */
#define VECTOR_011      SVC_Handler         /* 0x0000_002C 11 -         ARM core         Supervisor call (SVCall)                        */
#define VECTOR_012      default_isr         /* 0x0000_0030 12 -         ARM core         Debug Monitor                                   */
#define VECTOR_013      default_isr         /* 0x0000_0034 13 -                                                                          */
#define VECTOR_014      PendSV_Handler      /* 0x0000_0038 14 -                     Pendable request for system service (PendableSrvReq) */
#define VECTOR_015      SysTick_Handler     /* 0x0000_003C 15 -                          System tick timer (SysTick)                     */
#define VECTOR_016      default_isr         /* 0x0000_0040 16     0                                                                      */
#define VECTOR_017      default_isr         /* 0x0000_0044 17     1                                                                      */
#define VECTOR_018      default_isr         /* 0x0000_0048 18     2                                                                      */
#define VECTOR_019      default_isr         /* 0x0000_004C 19     3                                                                      */
#define VECTOR_020      default_isr         /* 0x0000_0050 20     4                                                                      */
#define VECTOR_021      default_isr         /* 0x0000_0054 21     5                                                                      */
#define VECTOR_022      default_isr         /* 0x0000_0058 22     6                                                                      */
#define VECTOR_023      default_isr         /* 0x0000_005C 23     7                                                                      */
#define VECTOR_024      default_isr         /* 0x0000_0060 24     8                                                                      */
#define VECTOR_025      default_isr         /* 0x0000_0064 25     9                                                                      */
#define VECTOR_026      default_isr         /* 0x0000_0068 26    10                                                                      */
#define VECTOR_027      default_isr         /* 0x0000_006C 27    11                                                                      */
#define VECTOR_028      default_isr         /* 0x0000_0070 28    12                                                                      */
#define VECTOR_029      default_isr         /* 0x0000_0074 29    13                                                                      */
#define VECTOR_030      default_isr         /* 0x0000_0078 30    14                                                                      */
#define VECTOR_031      default_isr         /* 0x0000_007C 31    15                                                                      */
#define VECTOR_032      default_isr         /* 0x0000_0080 32    16                                                                      */
#define VECTOR_033      default_isr         /* 0x0000_0084 33    17                                                                      */
#define VECTOR_034      default_isr         /* 0x0000_0088 34    18                                                                      */
#define VECTOR_035      default_isr         /* 0x0000_008C 35    19                                                                      */
#define VECTOR_036      default_isr         /* 0x0000_0090 36    20                                                                      */
#define VECTOR_037      default_isr         /* 0x0000_0094 37    21                                                                      */
#define VECTOR_038      default_isr         /* 0x0000_0098 38    22                                                                      */
#define VECTOR_039      default_isr         /* 0x0000_009C 39    23                                                                      */
#define VECTOR_040      default_isr         /* 0x0000_00A0 40    24                                                                      */
#define VECTOR_041      default_isr         /* 0x0000_00A4 41    25                                                                      */
#define VECTOR_042      default_isr         /* 0x0000_00A8 42    26                                                                      */
#define VECTOR_043      default_isr         /* 0x0000_00AC 43    27                                                                      */
#define VECTOR_044      default_isr         /* 0x0000_00B0 44    28                                                                      */
#define VECTOR_045      default_isr         /* 0x0000_00B4 45    29                                                                      */
#define VECTOR_046      default_isr         /* 0x0000_00B8 46    30                                                                      */
#define VECTOR_047      default_isr         /* 0x0000_00BC 47    31                                                                      */
#define VECTOR_048      default_isr         /* 0x0000_00C0 48    32                                                                      */
#define VECTOR_049      default_isr         /* 0x0000_00C4 49    33                                                                      */
#define VECTOR_050      default_isr         /* 0x0000_00C8 50    34                                                                      */
#define VECTOR_051      default_isr         /* 0x0000_00CC 51    35                                                                      */
#define VECTOR_052      default_isr         /* 0x0000_00D0 52    36                                                                      */
#define VECTOR_053      default_isr         /* 0x0000_00D4 53    37                                                                      */
#define VECTOR_054      default_isr         /* 0x0000_00D8 54    38                                                                      */
#define VECTOR_055      default_isr         /* 0x0000_00DC 55    39                                                                      */
#define VECTOR_056      default_isr         /* 0x0000_00E0 56    40                                                                      */
#define VECTOR_057      default_isr         /* 0x0000_00E4 57    41                                                                      */
#define VECTOR_058      default_isr         /* 0x0000_00E8 58    42                                                                      */
#define VECTOR_059      default_isr         /* 0x0000_00EC 59    43                                                                      */
#define VECTOR_060      default_isr         /* 0x0000_00F0 60    44                                                                      */
#define VECTOR_061      default_isr         /* 0x0000_00F4 61    45                                                                      */
#define VECTOR_062      default_isr         /* 0x0000_00F8 62    46                                                                      */
#define VECTOR_063      default_isr         /* 0x0000_00FC 63    47                                                                      */
#define VECTOR_064      default_isr         /* 0x0000_0100 64    48                                                                      */
#define VECTOR_065      default_isr         /* 0x0000_0104 65    49                                                                      */
#define VECTOR_066      default_isr         /* 0x0000_0108 66    50                                                                      */
#define VECTOR_067      default_isr         /* 0x0000_010C 67    51                                                                      */
#define VECTOR_068      default_isr         /* 0x0000_0110 68    52                                                                      */
#define VECTOR_069      default_isr         /* 0x0000_0114 69    53                                                                      */
#define VECTOR_070      default_isr         /* 0x0000_0118 70    54                                                                      */
#define VECTOR_071      default_isr         /* 0x0000_011C 71    55                                                                      */
#define VECTOR_072      default_isr         /* 0x0000_0120 72    56                                                                      */
#define VECTOR_073      default_isr         /* 0x0000_0124 73    57                                                                      */
#define VECTOR_074      default_isr         /* 0x0000_0128 74    58                                                                      */
#define VECTOR_075      default_isr         /* 0x0000_012C 75    59                                                                      */
#define VECTOR_076      default_isr         /* 0x0000_0130 76    60                                                                      */
#define VECTOR_077      default_isr         /* 0x0000_0134 77    61                                                                      */
#define VECTOR_078      default_isr         /* 0x0000_0138 78    62                                                                      */
#define VECTOR_079      default_isr         /* 0x0000_013C 79    63                                                                      */
#define VECTOR_080      default_isr         /* 0x0000_0140 80    64                                                                      */
#define VECTOR_081      default_isr         /* 0x0000_0144 81    65                                                                      */
#define VECTOR_082      default_isr         /* 0x0000_0148 82    66                                                                      */
#define VECTOR_083      default_isr         /* 0x0000_014C 83    67                                                                      */
#define VECTOR_084      default_isr         /* 0x0000_0150 84    68                                                                      */
#define VECTOR_085      default_isr         /* 0x0000_0154 85    69                                                                      */
#define VECTOR_086      default_isr         /* 0x0000_0158 86    70                                                                      */
#define VECTOR_087      default_isr         /* 0x0000_015C 87    71                                                                      */
#define VECTOR_088      default_isr         /* 0x0000_0160 88    72                                                                      */
#define VECTOR_089      default_isr         /* 0x0000_0164 89    73                                                                      */
#define VECTOR_090      default_isr         /* 0x0000_0168 90    74                                                                      */
#define VECTOR_091      default_isr         /* 0x0000_016C 91    75                                                                      */
#define VECTOR_092      default_isr         /* 0x0000_0170 92    76                                                                      */
#define VECTOR_093      default_isr         /* 0x0000_0174 93    77                                                                      */
#define VECTOR_094      default_isr         /* 0x0000_0178 94    78                                                                      */
#define VECTOR_095      default_isr         /* 0x0000_017C 95    79                                                                      */
#define VECTOR_096      default_isr         /* 0x0000_0180 96    80                                                                      */
#define VECTOR_097      default_isr         /* 0x0000_0184 97    81                                                                      */
#define VECTOR_098      default_isr         /* 0x0000_0188 98    82                                                                      */
#define VECTOR_099      default_isr         /* 0x0000_018C 99    83                                                                      */
#define VECTOR_100      default_isr         /* 0x0000_0190 100   84                                                                      */
#define VECTOR_101      default_isr         /* 0x0000_0194 101   85                                                                      */
#define VECTOR_102      default_isr         /* 0x0000_0198 102   86                                                                      */
#define VECTOR_103      default_isr         /* 0x0000_019C 103   87                                                                      */
#define VECTOR_104      default_isr         /* 0x0000_01A0 104   88                                                                      */
#define VECTOR_105      default_isr         /* 0x0000_01A4 105   89                                                                      */
#define VECTOR_106      default_isr         /* 0x0000_01A8 106   90                                                                      */
#define VECTOR_107      default_isr         /* 0x0000_01AC 107   91                                                                      */
#define VECTOR_108      default_isr         /* 0x0000_01B0 108   92                                                                      */
#define VECTOR_109      default_isr         /* 0x0000_01B4 109   93                                                                      */
#define VECTOR_110      default_isr         /* 0x0000_01B8 110   94                                                                      */
#define VECTOR_111      default_isr         /* 0x0000_01BC 111   95                                                                      */
#define VECTOR_112      default_isr         /* 0x0000_01C0 112   96                                                                      */
#define VECTOR_113      default_isr         /* 0x0000_01C4 113   97                                                                      */
#define VECTOR_114      default_isr         /* 0x0000_01C8 114   98                                                                      */
#define VECTOR_115      default_isr         /* 0x0000_01CC 115   99                                                                      */
#define VECTOR_116      default_isr         /* 0x0000_01D0 116   100                                                                     */
#define VECTOR_117      default_isr         /* 0x0000_01D4 117   101                                                                     */
#define VECTOR_118      default_isr         /* 0x0000_01D8 118   102                                                                     */
#define VECTOR_119      default_isr         /* 0x0000_01DC 119   103                                                                     */
#define VECTOR_120      default_isr                                                              
#define VECTOR_121      default_isr
#define VECTOR_122      default_isr
#define VECTOR_123      default_isr
#define VECTOR_124      default_isr
#define VECTOR_125      default_isr
#define VECTOR_126      default_isr
#define VECTOR_127      default_isr
#define VECTOR_128      default_isr
#define VECTOR_129      default_isr
#define VECTOR_130      default_isr
#define VECTOR_131      default_isr
#define VECTOR_132      default_isr
#define VECTOR_133      default_isr
#define VECTOR_134      default_isr
#define VECTOR_135      default_isr
#define VECTOR_136      default_isr
#define VECTOR_137      default_isr
#define VECTOR_138      default_isr
#define VECTOR_139      default_isr
#define VECTOR_140      default_isr
#define VECTOR_141      default_isr
#define VECTOR_142      default_isr
#define VECTOR_143      default_isr
#define VECTOR_144      default_isr
#define VECTOR_145      default_isr
#define VECTOR_146      default_isr
#define VECTOR_147      default_isr
#define VECTOR_148      default_isr
#define VECTOR_149      default_isr
#define VECTOR_150      default_isr
#define VECTOR_151      default_isr
#define VECTOR_152      default_isr
#define VECTOR_153      default_isr
#define VECTOR_154      default_isr
#define VECTOR_155      default_isr
#define VECTOR_156      default_isr
#define VECTOR_157      default_isr
#define VECTOR_158      default_isr
#define VECTOR_159      default_isr
#define VECTOR_160      default_isr
#define VECTOR_161      default_isr
#define VECTOR_162      default_isr
#define VECTOR_163      default_isr
#define VECTOR_164      default_isr
#define VECTOR_165      default_isr
#define VECTOR_166      default_isr
#define VECTOR_167      default_isr
#define VECTOR_168      default_isr
#define VECTOR_169      default_isr
#define VECTOR_170      default_isr
#define VECTOR_171      default_isr
#define VECTOR_172      default_isr
#define VECTOR_173      default_isr
#define VECTOR_174      default_isr
#define VECTOR_175      default_isr
#define VECTOR_176      default_isr
#define VECTOR_177      default_isr
#define VECTOR_178      default_isr
#define VECTOR_179      default_isr
#define VECTOR_180      default_isr
#define VECTOR_181      default_isr
#define VECTOR_182      default_isr
#define VECTOR_183      default_isr
#define VECTOR_184      default_isr
#define VECTOR_185      default_isr
#define VECTOR_186      default_isr
#define VECTOR_187      default_isr
#define VECTOR_188      default_isr
#define VECTOR_189      default_isr
#define VECTOR_190      default_isr
#define VECTOR_191      default_isr

#endif /*__VECTORS_H*/

/* End of "vectors.h" */
