macro INST_E rde, rs1, rs2, func, imm, op {
	if (imm > 0xFF)
		err 'imm in INST_E too big'
	end if

	db op
	db imm
	db (rs2 shl 4) + func
	db (rde shl 4) + rs1
}

macro INST_R rde, rs1, rs2, imm, op {
	if (imm > 0xFFF)
		err 'imm in INST_R too big'
	end if
	
	db op
	db (imm and 0xFF)
	db (rs2 shl 4) + (imm shr 8)
	db (rde shl 4) + rs1
}

macro INST_M rde, rs1, imm, op, se_state {
	if imm > 0xFFFF
		err 'imm in INST_M too big'
	end if

	se_imm = imm

	if se_state 
		se_imm = 0xFFFF + 1 - imm
	end if

	db op
	db (se_imm and 0xFF)
	db (se_imm shr 8)
	db (rde shl 4) + rs1
}

macro INST_F rde, func, imm, op {
	if imm > 0xFFFF
		err 'imm in INST_F too big'
	end if

	db op
	db (imm and 0xFF)
	db (imm shr 8)
	db (rde shl 4) + func
}

macro INST_B func, imm, op {
	if imm > 0xFFFFF
		err 'imm in INST_B too big'
	end if

	se_imm = $%% - imm ; get offset from label
	if se_imm < 0 
		se_imm = 0xFFFFF + 1 - se_imm/4 ; sign extend
	else 
		se_imm = se_imm/4
	end if

	

	db op
	db (se_imm and 0xFF)
	db (se_imm and 0xFF00) shr 8
	db (func shl 4) + (se_imm shr 16)
}