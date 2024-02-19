macro mov rd, rs {
	orr rd, rs, rz
}

macro li rd, imm {
	if imm <= 0xFFFF 
		llis rd, imm	
	else if imm <= 0xFFFFFFFF
		luis rd, (imm shr 16)
		lli rd, (imm and 0xFFFF)
	else if imm <= 0xFFFFFFFFFFFF
		ltis rd, (imm shr 32)
		lui rd, (imm and 0xFFFF0000) shr 16
		lli rd, (imm and 0xFFFF)
	else if imm <= 0xFFFFFFFFFFFFFFFF
		ltui rd, (imm shr 48)
		lti rd, (imm and 0xFFFF00000000) shr 32
		lui rd, (imm and 0xFFFF0000) shr 16
		lli rd, (imm and 0xFFFF)
	else
		err 'imm too big for li'
	end if
}

macro lli   rd, imm { INST_F rd, 0, imm, 0x10 }
macro llis  rd, imm { INST_F rd, 1, imm, 0x10 }
macro lui   rd, imm { INST_F rd, 2, imm, 0x10 }
macro luis  rd, imm { INST_F rd, 3, imm, 0x10 }
macro lti   rd, imm { INST_F rd, 4, imm, 0x10 }
macro ltis  rd, imm { INST_F rd, 5, imm, 0x10 }
macro ltui  rd, imm { INST_F rd, 6, imm, 0x10 }
macro ltuis rd, imm { INST_F rd, 7, imm, 0x10 }

macro lw rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x11
		else
			INST_E rd, rs, rn, 0,  off, 0x11
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x11
	end if 
}

macro lh rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x12
		else
			INST_E rd, rs, rn, 0,  off, 0x12
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x12
	end if 
}

macro lhs rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x13
		else
			INST_E rd, rs, rn, 0,  off, 0x13
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x13
	end if 
}

macro lq rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x14
		else
			INST_E rd, rs, rn, 0,  off, 0x14
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x14
	end if 
}

macro lqs rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x15
		else
			INST_E rd, rs, rn, 0,  off, 0x15
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x15
	end if 
}

macro lb rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x16
		else
			INST_E rd, rs, rn, 0,  off, 0x16
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x16
	end if 
}

macro lbs rd, rs, off, rn, sh {
	if rn eq
		if sh eq 
			INST_E rd, rs, 0,  0,  off, 0x17
		else
			INST_E rd, rs, rn, 0,  off, 0x17
		end if
	else
		INST_E rd, rs, rn, sh, off, 0x17
	end if 
}

macro sw rs, off, rn, sh, rd {
	if sh eq or rd eq
		err 'store instructions require all 5 operands due to fasmg limitations'
	end if
	INST_E rd, rs, rn, sh, off, 0x18
}

macro sh rs, off, rn, sh, rd {
	if sh eq or rd eq
		err 'store instructions require all 5 operands due to fasmg limitations'
	end if
	INST_E rd, rs, rn, sh, off, 0x19
}

macro sq rs, off, rn, sh, rd {
	if sh eq or rd eq
		err 'store instructions require all 5 operands due to fasmg limitations'
	end if
	INST_E rd, rs, rn, sh, off, 0x1a
}

macro sb rs, off, rn, sh, rd {
	if sh eq or rd eq
		err 'store instructions require all 5 operands due to fasmg limitations'
	end if
	INST_E rd, rs, rn, sh, off, 0x1b
}