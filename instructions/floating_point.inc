macro fcmp.16 r1, r2 { INST_E 0, r1, r2, 0, 0, 0x40 }
macro fcmp.32 r1, r2 { INST_E 0, r1, r2, 1, 0, 0x40 }
macro fcmp.64 r1, r2 { INST_E 0, r1, r2, 2, 0, 0x40 }

macro fto.16 rd, rs { INST_E rd, rs, 0, 0, 0, 0x41 }
macro fto.32 rd, rs { INST_E rd, rs, 0, 1, 0, 0x41 }
macro fto.64 rd, rs { INST_E rd, rs, 0, 2, 0, 0x41 }

macro ffrom.16 rd, rs { INST_E rd, rs, 0, 0, 0, 0x42 }
macro ffrom.32 rd, rs { INST_E rd, rs, 0, 1, 0, 0x42 }
macro ffrom.64 rd, rs { INST_E rd, rs, 0, 2, 0, 0x42 }

macro fneg.16 rd, rs { INST_E rd, rs, 0, 0, 0, 0x43 }
macro fneg.32 rd, rs { INST_E rd, rs, 0, 1, 0, 0x43 }
macro fneg.64 rd, rs { INST_E rd, rs, 0, 2, 0, 0x43 }

macro fabs.16 rd, rs { INST_E rd, rs, 0, 0, 0, 0x44 }
macro fabs.32 rd, rs { INST_E rd, rs, 0, 1, 0, 0x44 }
macro fabs.64 rd, rs { INST_E rd, rs, 0, 2, 0, 0x44 }

macro fadd.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x45 }
macro fadd.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x45 }
macro fadd.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x45 }

macro fsub.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x46 }
macro fsub.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x46 }
macro fsub.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x46 }

macro fmul.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x47 }
macro fmul.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x47 }
macro fmul.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x47 }

macro fdiv.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x48 }
macro fdiv.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x48 }
macro fdiv.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x48 }

macro fma.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x49 }
macro fma.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x49 }
macro fma.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x49 }

macro fsqrt.16 rd, rs { INST_E rd, rs, 0, 0, 0, 0x4a }
macro fsqrt.32 rd, rs { INST_E rd, rs, 0, 1, 0, 0x4a }
macro fsqrt.64 rd, rs { INST_E rd, rs, 0, 2, 0, 0x4a }

macro fmin.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x4b }
macro fmin.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x4b }
macro fmin.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x4b }

macro fmax.16 rde, rs1, rs2 { INST_E rde, rs1, rs2, 0, 0, 0x4c }
macro fmax.32 rde, rs1, rs2 { INST_E rde, rs1, rs2, 1, 0, 0x4c }
macro fmax.64 rde, rs1, rs2 { INST_E rde, rs1, rs2, 2, 0, 0x4c }

macro fsat.16 rd, r1 { INST_E rd, r1, 0, 0, 0, 0x4d }
macro fsat.32 rd, r1 { INST_E rd, r1, 0, 1, 0, 0x4d }
macro fsat.64 rd, r1 { INST_E rd, r1, 0, 2, 0, 0x4d }

macro fcnv.16.32 rd, r1 { INST_E rd, r1, 0, 1, 0, 0x4e }
macro fcnv.16.64 rd, r1 { INST_E rd, r1, 0, 2, 0, 0x4e }
macro fcnv.32.16 rd, r1 { INST_E rd, r1, 0, 4, 0, 0x4e }
macro fcnv.32.64 rd, r1 { INST_E rd, r1, 0, 6, 0, 0x4e }
macro fcnv.64.16 rd, r1 { INST_E rd, r1, 0, 8, 0, 0x4e }
macro fcnv.64.32 rd, r1 { INST_E rd, r1, 0, 9, 0, 0x4e }

macro fnan.16 rd, r1 { INST_E rd, r1, 0, 0, 0, 0x4f }
macro fnan.32 rd, r1 { INST_E rd, r1, 0, 1, 0, 0x4f }
macro fnan.64 rd, r1 { INST_E rd, r1, 0, 2, 0, 0x4f }