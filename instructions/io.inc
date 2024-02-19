macro out {
	err 'out is not supported yet'
}

macro in {
	err 'in is not supported yet'
}

macro outr rd, rs {
	INST_M rd, rs, 0, 0x02, 0
}

macro outi imm, rs {
	INST_F rd, 0, imm, 0x03
}

macro inr rs, rd {
	INST_M rs, rd, 0, 0x04, 0
}

macro ini imm, rd {
	INST_F rd, 0, imm, 0x05
}