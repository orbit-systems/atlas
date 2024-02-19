irp value, add,sub,imul,umul,idiv,udiv,rem,mod {
	macro value {
		err 'generic arithmetic instructions are not supported yet'
	}
}

macro ARITH_M rde, rs1, imm, op {
	if imm > 0xFFFF 
		err 'imm too big for arithmetic instruction'
	end if

	se_imm = imm

	if imm < 0 
		se_imm = 0xFFFF + imm + 1
	end if

	INST_M rde, rs1, imm, op, 0 
}

macro addr  rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x20 }
macro addi  rde, rs1, imm { ARITH_M rde, rs1, imm, 0x21 }
macro subr  rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x22 }
macro subi  rde, rs1, imm { ARITH_M rde, rs1, imm, 0x23 }
macro imulr rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x24 }
macro imuli rde, rs1, imm { ARITH_M rde, rs1, imm, 0x25 }
macro idivr rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x26 }
macro idivi rde, rs1, imm { ARITH_M rde, rs1, imm, 0x27 }
macro umulr rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x28 }
macro umuli rde, rs1, imm { ARITH_M rde, rs1, imm, 0x29 }
macro udivr rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x2a }
macro udivi rde, rs1, imm { ARITH_M rde, rs1, imm, 0x2b }
macro remr  rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x2c }
macro remi  rde, rs1, imm { ARITH_M rde, rs1, imm, 0x2d }
macro modr  rde, rs1, rs2 { INST_R  rde, rs1, rs2, 0, 0x2e }
macro modi  rde, rs1, imm { ARITH_M rde, rs1, imm, 0x2f }

irp value, and,or,nor,xor,shl,asr,lsr,bit {
	macro value {
		err 'generic bitwise instructions are not supported yet'
	}
}

macro not rd, rs { norr rd, rs, rz }
macro andr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x30 }
macro andi rd, r1, imm { INST_M rd, r1, imm, 0x31, 0 }
macro orr  rd, r1, r2  { INST_R rd, r1, r2, 0, 0x32 }
macro ori  rd, r1, imm { INST_M rd, r1, imm, 0x33, 0 }
macro norr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x34 }
macro nori rd, r1, imm { INST_M rd, r1, imm, 0x35, 0 }
macro xorr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x36 }
macro xori rd, r1, imm { INST_M rd, r1, imm, 0x37, 0 }
macro shlr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x38 }
macro shli rd, r1, imm { INST_M rd, r1, imm, 0x39, 0 }
macro asrr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x3a }
macro asri rd, r1, imm { INST_M rd, r1, imm, 0x3b, 0 }
macro lsrr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x3c }
macro lsri rd, r1, imm { INST_M rd, r1, imm, 0x3d, 0 }
macro bitr rd, r1, r2  { INST_R rd, r1, r2, 0, 0x3e }
macro biti rd, r1, imm { INST_M rd, r1, imm, 0x3f, 0 }

macro setfs   rd { biti rd, st, 0 }
macro setfz   rd { biti rd, st, 1 }
macro setfcb  rd { biti rd, st, 2 }
macro setfcbu rd { biti rd, st, 3 }
macro setfe   rd { biti rd, st, 4 }
macro setfl   rd { biti rd, st, 5 }
macro setflu  rd { biti rd, st, 6 }