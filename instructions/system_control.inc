macro nop {
	addr rz, rz rz
}

macro inv {
	int 2
}

macro int imm {
	if imm > 0xFF 
		err 'int is u8 value'
	end if

	INST_F 0, 0, imm, 0x01
}

macro iret {
	INST_F 0, 1, 0, 0x01
}

macro ires {
	INST_F 0, 2, 0, 0x01
}

macro usr rd {
	INST_F rd, 3, 0, 0x01
}