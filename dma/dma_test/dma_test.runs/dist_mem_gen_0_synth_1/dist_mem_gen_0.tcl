# 
# Synthesis run script generated by Vivado
# 

debug::add_scope template.lib 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7z020clg484-1

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.cache/wt [current_project]
set_property parent.project_path /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part em.avnet.com:zed:part0:1.3 [current_project]
read_ip /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0.xci
set_property is_locked true [get_files /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0.xci]

read_xdc dont_touch.xdc
set_property used_in_implementation false [get_files dont_touch.xdc]
synth_design -top dist_mem_gen_0 -part xc7z020clg484-1 -mode out_of_context
rename_ref -prefix_all dist_mem_gen_0_
write_checkpoint -noxdef dist_mem_gen_0.dcp
catch { report_utilization -file dist_mem_gen_0_utilization_synth.rpt -pb dist_mem_gen_0_utilization_synth.pb }
if { [catch {
  file copy -force /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.runs/dist_mem_gen_0_synth_1/dist_mem_gen_0.dcp /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0.dcp
} _RESULT ] } { 
  error "ERROR: Unable to successfully create or copy the sub-design checkpoint file."
}
if { [catch {
  write_verilog -force -mode synth_stub /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_stub.v
} _RESULT ] } { 
  puts "CRITICAL WARNING: Unable to successfully create a Verilog synthesis stub for the sub-design. This may lead to errors in top level synthesis of the design. Error reported: $_RESULT"
}
if { [catch {
  write_vhdl -force -mode synth_stub /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_stub.vhdl
} _RESULT ] } { 
  puts "CRITICAL WARNING: Unable to successfully create a VHDL synthesis stub for the sub-design. This may lead to errors in top level synthesis of the design. Error reported: $_RESULT"
}
if { [catch {
  write_verilog -force -mode funcsim /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_funcsim.v
} _RESULT ] } { 
  puts "CRITICAL WARNING: Unable to successfully create the Verilog functional simulation sub-design file. Post-Synthesis Functional Simulation with this file may not be possible or may give incorrect results. Error reported: $_RESULT"
}
if { [catch {
  write_vhdl -force -mode funcsim /afs/ece.cmu.edu/usr/ryanovsk/Private/18545/GBA/dma/dma_test/dma_test.srcs/sources_1/ip/dist_mem_gen_0/dist_mem_gen_0_funcsim.vhdl
} _RESULT ] } { 
  puts "CRITICAL WARNING: Unable to successfully create the VHDL functional simulation sub-design file. Post-Synthesis Functional Simulation with this file may not be possible or may give incorrect results. Error reported: $_RESULT"
}
