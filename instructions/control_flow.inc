macro jal rs, imm {
	se_imm = $%% - imm ; get offset from label
	se_imm = 0xFFFFF + 1 - se_imm/4 ; sign extend

	INST_M 0, rs, se_imm, 0x06, 0
}

macro jalr rs, imm, rd {
	se_imm = $%% - imm ; get offset from label
	se_imm = 0xFFFFF + 1 - se_imm/4 ; sign extend

	INST_M rd, rs, se_imm, 0x07, 0
}

macro ret {
	INST_M 0, 0, 0, 0x08, 0
}

macro retr rs {
	INST_M 0, rs, 0, 0x09, 0
}

macro bra  imm { INST_B 0x0, imm, 0x0a }
macro beq  imm { INST_B 0x1, imm, 0x0a }
macro bez  imm { INST_B 0x2, imm, 0x0a }
macro blt  imm { INST_B 0x3, imm, 0x0a }
macro ble  imm { INST_B 0x4, imm, 0x0a }
macro bltu imm { INST_B 0x5, imm, 0x0a }
macro bleu imm { INST_B 0x6, imm, 0x0a }
macro bne  imm { INST_B 0x9, imm, 0x0a }
macro bnz  imm { INST_B 0xA, imm, 0x0a }
macro bge  imm { INST_B 0xB, imm, 0x0a }
macro bgt  imm { INST_B 0xC, imm, 0x0a }
macro bgeu imm { INST_B 0xD, imm, 0x0a }
macro bgtu imm { INST_B 0xE, imm, 0x0a }

macro cmp {
	err 'cmp is not supported yet'
}

macro cmpr r1, r2 {
	INST_M r1, r2, 0, 0x1e, 0
}

macro cmpi r1, imm {
	se_imm = imm
	if (imm < 0) 
		se_imm = 0xFFFF + imm + 1;
	end if
	display 'NOTE: YOU ARE USING CMPI - fasmg only supports cmpi r1, imm'
	INST_F r1, 0, imm, 0x1f	
}