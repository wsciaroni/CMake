include(RunCMake)

run_cmake(no_parameters)
run_cmake(unknown_meta_operation)
foreach(command IN ITEMS
    "function" "ENDFUNCTION"
    "macro" "endMACRO"
    "if" "elseif" "else" "endif"
    "while" "endwhile"
    "foreach" "endforeach"
    )
  message(STATUS "Running call_invalid_command for ${command}...")
  run_cmake_with_options(call_invalid_command -Dcommand=${command})
endforeach()
run_cmake(call_valid_command)
run_cmake(call_double_evaluation)
run_cmake(call_expanded_command)
run_cmake(call_expanded_command_and_arguments)
run_cmake(call_expanded_command_with_explicit_argument)
run_cmake(call_expand_command_name)
run_cmake(call_expand_function_name)
run_cmake(call_message)
run_cmake(call_message_fatal_error)
run_cmake(call_no_parameters)
run_cmake(call_preserve_arguments)
run_cmake(call_unknown_function)
run_cmake(eval_expand_command_name)
run_cmake(eval_expanded_command_and_arguments)
run_cmake(eval_extra_parameters_between_eval_and_code)
run_cmake(eval_message)
run_cmake(eval_message_fatal_error)
run_cmake(eval_no_code)
run_cmake(eval_no_parameters)
run_cmake(eval_variable_outside_message)
