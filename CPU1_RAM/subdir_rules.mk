################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-1781145407: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Applications/ti/ccstheia140/ccs/utils/sysconfig_1.20.0/sysconfig_cli.sh" --script "/Users/nov4ou/workspace_ccstheia/Inverter_syscfg/c2000.syscfg" -o "syscfg" -s "/Applications/ti/c2000/C2000Ware_5_02_00_00/.metadata/sdk.json" -d "F28004x" --package F28004x_100PZ --part F28004x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1781145407 ../c2000.syscfg
syscfg/board.h: build-1781145407
syscfg/board.cmd.genlibs: build-1781145407
syscfg/board.opt: build-1781145407
syscfg/board.json: build-1781145407
syscfg/pinmux.csv: build-1781145407
syscfg/epwm.dot: build-1781145407
syscfg/adc.dot: build-1781145407
syscfg/c2000ware_libraries.cmd.genlibs: build-1781145407
syscfg/c2000ware_libraries.opt: build-1781145407
syscfg/c2000ware_libraries.c: build-1781145407
syscfg/c2000ware_libraries.h: build-1781145407
syscfg/clocktree.h: build-1781145407
syscfg: build-1781145407

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg" --include_path="/Applications/ti/c2000/C2000Ware_5_02_00_00" --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg/device" --include_path="/Applications/ti/c2000/C2000Ware_5_02_00_00/driverlib/f28004x/driverlib" --include_path="/Applications/ti/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg" --include_path="/Applications/ti/c2000/C2000Ware_5_02_00_00" --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg/device" --include_path="/Applications/ti/c2000/C2000Ware_5_02_00_00/driverlib/f28004x/driverlib" --include_path="/Applications/ti/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="/Users/nov4ou/workspace_ccstheia/Inverter_syscfg/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


