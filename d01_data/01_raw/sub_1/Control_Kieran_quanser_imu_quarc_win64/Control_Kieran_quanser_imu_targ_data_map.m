  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Kieran_quanser_imu_P)
    ;%
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.GravityCompensationPositiveDeri
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_input_maxi
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_input_mini
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_output_max
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_output_min
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_encoder_filter_fr
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_final_analog_outp
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_final_pwm_outputs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_initial_analog_ou
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_initial_pwm_outpu
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_input_
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_input
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_input
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter5_input
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter6_input
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter7_input
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter8_input
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter9_input
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_h
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_n
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter3_input
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_e
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_c
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter5_inp_k
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter6_inp_i
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter7_inp_n
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter8_inp_h
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter9_inp_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter1_inp_f
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter2_inp_o
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter3_inp_m
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_P.SecondOrderLowPassFilter_inpu_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_d
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_h
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Control_Kieran_quanser_imu_P.GravityCompensationPositiveDe_a
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_frequency
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_leading_deadb
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_trailing_dead
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_other_outputs
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_other_outpu_i
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_other_outpu_o
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_other_outp_if
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_watchdog_analog_o
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_watchdog_pwm_outp
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_hardware_clocks
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_initial_encoder_c
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_alignment
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_configuration
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_modes
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_polarity
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_watchdog_digital_
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 55;
	  section.data(2).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog3_channels
	  section.data(3).logicalSrcIdx = 56;
	  section.data(3).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog1_channels
	  section.data(4).logicalSrcIdx = 57;
	  section.data(4).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_P.LowLvSpeedController_channels
	  section.data(5).logicalSrcIdx = 58;
	  section.data(5).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadDigital_channels
	  section.data(6).logicalSrcIdx = 59;
	  section.data(6).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog_channels
	  section.data(7).logicalSrcIdx = 60;
	  section.data(7).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog2_channels
	  section.data(8).logicalSrcIdx = 61;
	  section.data(8).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog4_channels
	  section.data(9).logicalSrcIdx = 62;
	  section.data(9).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_digital_input_cha
	  section.data(10).logicalSrcIdx = 63;
	  section.data(10).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_digital_output_ch
	  section.data(11).logicalSrcIdx = 64;
	  section.data(11).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_encoder_channels
	  section.data(12).logicalSrcIdx = 65;
	  section.data(12).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_pwm_channels
	  section.data(13).logicalSrcIdx = 66;
	  section.data(13).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_quadrature
	  section.data(14).logicalSrcIdx = 67;
	  section.data(14).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.StopwithMessage1_message_icon
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.StopwithMessage_message_icon
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.Texttospeak1_alignment
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.Texttospeak1_display_mode
	  section.data(2).logicalSrcIdx = 71;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 36;
      section.data(36)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 73;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 74;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_interrupt
	  section.data(4).logicalSrcIdx = 75;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_input_
	  section.data(5).logicalSrcIdx = 76;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_inpu_k
	  section.data(6).logicalSrcIdx = 77;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_output
	  section.data(7).logicalSrcIdx = 78;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_f
	  section.data(8).logicalSrcIdx = 79;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_out_fp
	  section.data(9).logicalSrcIdx = 80;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_e
	  section.data(10).logicalSrcIdx = 81;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_d
	  section.data(11).logicalSrcIdx = 82;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_k
	  section.data(12).logicalSrcIdx = 83;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_analog_outp_i
	  section.data(13).logicalSrcIdx = 84;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_clock_frequen
	  section.data(14).logicalSrcIdx = 85;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_clock_frequ_k
	  section.data(15).logicalSrcIdx = 86;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_clock_params_
	  section.data(16).logicalSrcIdx = 87;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_clock_param_a
	  section.data(17).logicalSrcIdx = 88;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_outpu
	  section.data(18).logicalSrcIdx = 89;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_c
	  section.data(19).logicalSrcIdx = 90;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_p
	  section.data(20).logicalSrcIdx = 91;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_e
	  section.data(21).logicalSrcIdx = 92;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_l
	  section.data(22).logicalSrcIdx = 93;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_out_a
	  section.data(23).logicalSrcIdx = 94;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_digital_ou_lc
	  section.data(24).logicalSrcIdx = 95;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_count
	  section.data(25).logicalSrcIdx = 96;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_cou_o
	  section.data(26).logicalSrcIdx = 97;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_param
	  section.data(27).logicalSrcIdx = 98;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_encoder_par_a
	  section.data(28).logicalSrcIdx = 99;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_other_outpu_h
	  section.data(29).logicalSrcIdx = 100;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_a
	  section.data(30).logicalSrcIdx = 101;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_e
	  section.data(31).logicalSrcIdx = 102;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_j
	  section.data(32).logicalSrcIdx = 103;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_b
	  section.data(33).logicalSrcIdx = 104;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_outputs_o
	  section.data(34).logicalSrcIdx = 105;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_params_at
	  section.data(35).logicalSrcIdx = 106;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Control_Kieran_quanser_imu_P.HILInitialize_set_pwm_params__h
	  section.data(36).logicalSrcIdx = 107;
	  section.data(36).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 113;
      section.data(113)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.Out2_Y0
	  section.data(2).logicalSrcIdx = 109;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value
	  section.data(3).logicalSrcIdx = 110;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.Memory_X0
	  section.data(4).logicalSrcIdx = 111;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 112;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_P.Constant4_Value
	  section.data(6).logicalSrcIdx = 113;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_P.Constant3_Value
	  section.data(7).logicalSrcIdx = 114;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_P.Gain_Gain
	  section.data(8).logicalSrcIdx = 115;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_c
	  section.data(9).logicalSrcIdx = 116;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_d
	  section.data(10).logicalSrcIdx = 117;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_k
	  section.data(11).logicalSrcIdx = 118;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_a
	  section.data(12).logicalSrcIdx = 119;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_i
	  section.data(13).logicalSrcIdx = 120;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_cw
	  section.data(14).logicalSrcIdx = 121;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_g
	  section.data(15).logicalSrcIdx = 122;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_P.Gain_Gain_d
	  section.data(16).logicalSrcIdx = 123;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_o
	  section.data(17).logicalSrcIdx = 124;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_P.Left_Value
	  section.data(18).logicalSrcIdx = 125;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_P.Right_Value
	  section.data(19).logicalSrcIdx = 126;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.Off_Value
	  section.data(20).logicalSrcIdx = 127;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_P.On_Value
	  section.data(21).logicalSrcIdx = 128;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_P.Constant6_Value
	  section.data(22).logicalSrcIdx = 129;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_P.Gain_Gain_n
	  section.data(23).logicalSrcIdx = 130;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_P.Gain4_Gain
	  section.data(24).logicalSrcIdx = 131;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_P.Gain2_Gain
	  section.data(25).logicalSrcIdx = 132;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_P.Constant5_Value
	  section.data(26).logicalSrcIdx = 133;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_P.Gain1_Gain
	  section.data(27).logicalSrcIdx = 134;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_P.Wireonotherside1_Gain
	  section.data(28).logicalSrcIdx = 135;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value
	  section.data(29).logicalSrcIdx = 136;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_h
	  section.data(30).logicalSrcIdx = 137;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_P.Gain3_Gain
	  section.data(31).logicalSrcIdx = 138;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_cp
	  section.data(32).logicalSrcIdx = 139;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_P.Left3_Value
	  section.data(33).logicalSrcIdx = 140;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_P.Left1_Value
	  section.data(34).logicalSrcIdx = 141;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Control_Kieran_quanser_imu_P.forearm_m_Gain
	  section.data(35).logicalSrcIdx = 142;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Control_Kieran_quanser_imu_P.forearm_lc_Gain
	  section.data(36).logicalSrcIdx = 143;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Control_Kieran_quanser_imu_P.Gain4_Gain_l
	  section.data(37).logicalSrcIdx = 144;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Control_Kieran_quanser_imu_P.Left2_Value
	  section.data(38).logicalSrcIdx = 145;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Control_Kieran_quanser_imu_P.forearmL_Gain
	  section.data(39).logicalSrcIdx = 146;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Control_Kieran_quanser_imu_P.Gain3_Gain_p
	  section.data(40).logicalSrcIdx = 147;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_P.g_Gain
	  section.data(41).logicalSrcIdx = 148;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_P.Gain2_Gain_o
	  section.data(42).logicalSrcIdx = 149;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_l
	  section.data(43).logicalSrcIdx = 150;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Control_Kieran_quanser_imu_P.deg2rad_Gain
	  section.data(44).logicalSrcIdx = 151;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_c
	  section.data(45).logicalSrcIdx = 152;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_e
	  section.data(46).logicalSrcIdx = 153;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Control_Kieran_quanser_imu_P.Gain_Gain_i
	  section.data(47).logicalSrcIdx = 154;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Control_Kieran_quanser_imu_P.Gain1_Gain_k
	  section.data(48).logicalSrcIdx = 155;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Control_Kieran_quanser_imu_P.ahalf_width_Value
	  section.data(49).logicalSrcIdx = 156;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Control_Kieran_quanser_imu_P.half_width1_Value
	  section.data(50).logicalSrcIdx = 157;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator_IC
	  section.data(51).logicalSrcIdx = 158;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC
	  section.data(52).logicalSrcIdx = 159;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_m
	  section.data(53).logicalSrcIdx = 160;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Control_Kieran_quanser_imu_P.Constant1_Value_m
	  section.data(54).logicalSrcIdx = 161;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Control_Kieran_quanser_imu_P.Merge6_InitialOutput
	  section.data(55).logicalSrcIdx = 162;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Control_Kieran_quanser_imu_P.Merge1_InitialOutput
	  section.data(56).logicalSrcIdx = 163;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Control_Kieran_quanser_imu_P.Wireonotherside_Gain
	  section.data(57).logicalSrcIdx = 164;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_g
	  section.data(58).logicalSrcIdx = 165;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_b
	  section.data(59).logicalSrcIdx = 166;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_p
	  section.data(60).logicalSrcIdx = 167;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_a
	  section.data(61).logicalSrcIdx = 168;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Control_Kieran_quanser_imu_P.Left4_Value
	  section.data(62).logicalSrcIdx = 169;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_n
	  section.data(63).logicalSrcIdx = 170;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Control_Kieran_quanser_imu_P.Memory1_X0
	  section.data(64).logicalSrcIdx = 171;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Control_Kieran_quanser_imu_P.Constant7_Value
	  section.data(65).logicalSrcIdx = 172;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Control_Kieran_quanser_imu_P.Amplitude3_Gain
	  section.data(66).logicalSrcIdx = 173;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_cf
	  section.data(67).logicalSrcIdx = 174;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Control_Kieran_quanser_imu_P.Merge_InitialOutput
	  section.data(68).logicalSrcIdx = 175;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_m
	  section.data(69).logicalSrcIdx = 176;
	  section.data(69).dtTransOffset = 68;
	
	  ;% Control_Kieran_quanser_imu_P.offset4_Value
	  section.data(70).logicalSrcIdx = 177;
	  section.data(70).dtTransOffset = 69;
	
	  ;% Control_Kieran_quanser_imu_P.Gain5_Gain
	  section.data(71).logicalSrcIdx = 178;
	  section.data(71).dtTransOffset = 70;
	
	  ;% Control_Kieran_quanser_imu_P.offset5_Value
	  section.data(72).logicalSrcIdx = 179;
	  section.data(72).dtTransOffset = 71;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_e
	  section.data(73).logicalSrcIdx = 180;
	  section.data(73).dtTransOffset = 72;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_p
	  section.data(74).logicalSrcIdx = 181;
	  section.data(74).dtTransOffset = 73;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_p
	  section.data(75).logicalSrcIdx = 182;
	  section.data(75).dtTransOffset = 74;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_n
	  section.data(76).logicalSrcIdx = 183;
	  section.data(76).dtTransOffset = 75;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_ct
	  section.data(77).logicalSrcIdx = 184;
	  section.data(77).dtTransOffset = 76;
	
	  ;% Control_Kieran_quanser_imu_P.x0_Value_ec
	  section.data(78).logicalSrcIdx = 185;
	  section.data(78).dtTransOffset = 77;
	
	  ;% Control_Kieran_quanser_imu_P.deg2rad1_Gain
	  section.data(79).logicalSrcIdx = 186;
	  section.data(79).dtTransOffset = 78;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_mw
	  section.data(80).logicalSrcIdx = 187;
	  section.data(80).dtTransOffset = 79;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_g
	  section.data(81).logicalSrcIdx = 188;
	  section.data(81).dtTransOffset = 80;
	
	  ;% Control_Kieran_quanser_imu_P.val1_Value
	  section.data(82).logicalSrcIdx = 189;
	  section.data(82).dtTransOffset = 81;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_l
	  section.data(83).logicalSrcIdx = 190;
	  section.data(83).dtTransOffset = 82;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_c
	  section.data(84).logicalSrcIdx = 191;
	  section.data(84).dtTransOffset = 83;
	
	  ;% Control_Kieran_quanser_imu_P.val2_Value
	  section.data(85).logicalSrcIdx = 192;
	  section.data(85).dtTransOffset = 84;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_de
	  section.data(86).logicalSrcIdx = 193;
	  section.data(86).dtTransOffset = 85;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_f
	  section.data(87).logicalSrcIdx = 194;
	  section.data(87).dtTransOffset = 86;
	
	  ;% Control_Kieran_quanser_imu_P.val3_Value
	  section.data(88).logicalSrcIdx = 195;
	  section.data(88).dtTransOffset = 87;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_mg
	  section.data(89).logicalSrcIdx = 196;
	  section.data(89).dtTransOffset = 88;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_l
	  section.data(90).logicalSrcIdx = 197;
	  section.data(90).dtTransOffset = 89;
	
	  ;% Control_Kieran_quanser_imu_P.val4_Value
	  section.data(91).logicalSrcIdx = 198;
	  section.data(91).dtTransOffset = 90;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_b
	  section.data(92).logicalSrcIdx = 199;
	  section.data(92).dtTransOffset = 91;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_i
	  section.data(93).logicalSrcIdx = 200;
	  section.data(93).dtTransOffset = 92;
	
	  ;% Control_Kieran_quanser_imu_P.val5_Value
	  section.data(94).logicalSrcIdx = 201;
	  section.data(94).dtTransOffset = 93;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_h
	  section.data(95).logicalSrcIdx = 202;
	  section.data(95).dtTransOffset = 94;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_im
	  section.data(96).logicalSrcIdx = 203;
	  section.data(96).dtTransOffset = 95;
	
	  ;% Control_Kieran_quanser_imu_P.val6_Value
	  section.data(97).logicalSrcIdx = 204;
	  section.data(97).dtTransOffset = 96;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_ht
	  section.data(98).logicalSrcIdx = 205;
	  section.data(98).dtTransOffset = 97;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_a
	  section.data(99).logicalSrcIdx = 206;
	  section.data(99).dtTransOffset = 98;
	
	  ;% Control_Kieran_quanser_imu_P.val7_Value
	  section.data(100).logicalSrcIdx = 207;
	  section.data(100).dtTransOffset = 99;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_m4
	  section.data(101).logicalSrcIdx = 208;
	  section.data(101).dtTransOffset = 100;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_fa
	  section.data(102).logicalSrcIdx = 209;
	  section.data(102).dtTransOffset = 101;
	
	  ;% Control_Kieran_quanser_imu_P.val8_Value
	  section.data(103).logicalSrcIdx = 210;
	  section.data(103).dtTransOffset = 102;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_ar
	  section.data(104).logicalSrcIdx = 211;
	  section.data(104).dtTransOffset = 103;
	
	  ;% Control_Kieran_quanser_imu_P.Integrator2_IC_d
	  section.data(105).logicalSrcIdx = 212;
	  section.data(105).dtTransOffset = 104;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_o3
	  section.data(106).logicalSrcIdx = 213;
	  section.data(106).dtTransOffset = 105;
	
	  ;% Control_Kieran_quanser_imu_P.tos_Gain
	  section.data(107).logicalSrcIdx = 214;
	  section.data(107).dtTransOffset = 106;
	
	  ;% Control_Kieran_quanser_imu_P.Amplitude4_Gain
	  section.data(108).logicalSrcIdx = 215;
	  section.data(108).dtTransOffset = 107;
	
	  ;% Control_Kieran_quanser_imu_P.Constant1_Value_g
	  section.data(109).logicalSrcIdx = 216;
	  section.data(109).dtTransOffset = 108;
	
	  ;% Control_Kieran_quanser_imu_P.Constant2_Value
	  section.data(110).logicalSrcIdx = 217;
	  section.data(110).dtTransOffset = 109;
	
	  ;% Control_Kieran_quanser_imu_P.Constant3_Value_n
	  section.data(111).logicalSrcIdx = 218;
	  section.data(111).dtTransOffset = 110;
	
	  ;% Control_Kieran_quanser_imu_P.Constant4_Value_l
	  section.data(112).logicalSrcIdx = 219;
	  section.data(112).dtTransOffset = 111;
	
	  ;% Control_Kieran_quanser_imu_P.Constant_Value_ld
	  section.data(113).logicalSrcIdx = 220;
	  section.data(113).dtTransOffset = 112;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_SendBufferSize
	  section.data(1).logicalSrcIdx = 221;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_ReceiveBufferSiz
	  section.data(2).logicalSrcIdx = 222;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_ThreadPriority
	  section.data(3).logicalSrcIdx = 223;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.ToHostFile1_Decimation
	  section.data(1).logicalSrcIdx = 224;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile2_Decimation
	  section.data(2).logicalSrcIdx = 225;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile5_Decimation
	  section.data(3).logicalSrcIdx = 226;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile3_Decimation
	  section.data(4).logicalSrcIdx = 227;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile4_Decimation
	  section.data(5).logicalSrcIdx = 228;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile6_Decimation
	  section.data(6).logicalSrcIdx = 229;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Rate
	  section.data(1).logicalSrcIdx = 230;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Pitch
	  section.data(2).logicalSrcIdx = 231;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_URI
	  section.data(1).logicalSrcIdx = 232;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.ManualSwitch2_CurrentSetting
	  section.data(2).logicalSrcIdx = 233;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.ManualSwitch3_CurrentSetting
	  section.data(3).logicalSrcIdx = 234;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.StringSelect_Strings
	  section.data(4).logicalSrcIdx = 235;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.StringSelect_DefaultString
	  section.data(5).logicalSrcIdx = 236;
	  section.data(5).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Gender
	  section.data(6).logicalSrcIdx = 237;
	  section.data(6).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Age
	  section.data(7).logicalSrcIdx = 238;
	  section.data(7).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Volume
	  section.data(8).logicalSrcIdx = 239;
	  section.data(8).dtTransOffset = 41;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_OutputMode
	  section.data(9).logicalSrcIdx = 240;
	  section.data(9).dtTransOffset = 42;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile1_file_name
	  section.data(10).logicalSrcIdx = 241;
	  section.data(10).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile1_VarName
	  section.data(11).logicalSrcIdx = 242;
	  section.data(11).dtTransOffset = 104;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile1_FileFormat
	  section.data(12).logicalSrcIdx = 243;
	  section.data(12).dtTransOffset = 115;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile2_file_name
	  section.data(13).logicalSrcIdx = 244;
	  section.data(13).dtTransOffset = 116;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile2_VarName
	  section.data(14).logicalSrcIdx = 245;
	  section.data(14).dtTransOffset = 163;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile2_FileFormat
	  section.data(15).logicalSrcIdx = 246;
	  section.data(15).dtTransOffset = 168;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile5_file_name
	  section.data(16).logicalSrcIdx = 247;
	  section.data(16).dtTransOffset = 169;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile5_VarName
	  section.data(17).logicalSrcIdx = 248;
	  section.data(17).dtTransOffset = 214;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile5_FileFormat
	  section.data(18).logicalSrcIdx = 249;
	  section.data(18).dtTransOffset = 228;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile3_file_name
	  section.data(19).logicalSrcIdx = 250;
	  section.data(19).dtTransOffset = 229;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile3_VarName
	  section.data(20).logicalSrcIdx = 251;
	  section.data(20).dtTransOffset = 278;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile3_FileFormat
	  section.data(21).logicalSrcIdx = 252;
	  section.data(21).dtTransOffset = 288;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile4_file_name
	  section.data(22).logicalSrcIdx = 253;
	  section.data(22).dtTransOffset = 289;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile4_VarName
	  section.data(23).logicalSrcIdx = 254;
	  section.data(23).dtTransOffset = 336;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile4_FileFormat
	  section.data(24).logicalSrcIdx = 255;
	  section.data(24).dtTransOffset = 341;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile6_file_name
	  section.data(25).logicalSrcIdx = 256;
	  section.data(25).dtTransOffset = 342;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile6_VarName
	  section.data(26).logicalSrcIdx = 257;
	  section.data(26).dtTransOffset = 389;
	
	  ;% Control_Kieran_quanser_imu_P.ToHostFile6_FileFormat
	  section.data(27).logicalSrcIdx = 258;
	  section.data(27).dtTransOffset = 393;
	
	  ;% Control_Kieran_quanser_imu_P.ManualSwitch_CurrentSetting
	  section.data(28).logicalSrcIdx = 259;
	  section.data(28).dtTransOffset = 394;
	
	  ;% Control_Kieran_quanser_imu_P.ManualSwitch1_CurrentSetting
	  section.data(29).logicalSrcIdx = 260;
	  section.data(29).dtTransOffset = 395;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_RunClient
	  section.data(1).logicalSrcIdx = 261;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_UseWindow
	  section.data(2).logicalSrcIdx = 262;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_P.HostInitialize_Active
	  section.data(3).logicalSrcIdx = 263;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_P.SystemTimebase_StopOnOverrun
	  section.data(4).logicalSrcIdx = 264;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog3_Active
	  section.data(5).logicalSrcIdx = 265;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog1_Active
	  section.data(6).logicalSrcIdx = 266;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_P.LowLvSpeedController_Active
	  section.data(7).logicalSrcIdx = 267;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadDigital_Active
	  section.data(8).logicalSrcIdx = 268;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_P.HostSpeechSynthesis1_Enabled
	  section.data(9).logicalSrcIdx = 269;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog_Active
	  section.data(10).logicalSrcIdx = 270;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog2_Active
	  section.data(11).logicalSrcIdx = 271;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_P.HILReadAnalog4_Active
	  section.data(12).logicalSrcIdx = 272;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Kieran_quanser_imu_B)
    ;%
      section.nData     = 91;
      section.data(91)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_B.ManualSwitch2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_B.ManualSwitch3
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_B.HILReadAnalog3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_B.Subtract1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_B.Gain4
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_B.Gain2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_B.HILReadAnalog1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_B.Merge2
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_B.Wireonotherside1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_B.x0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_B.x0_m
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_k
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_B.Left3
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_B.Left1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_B.Left2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_B.g
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_B.Product
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_B.TrigonometricFunction
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_B.x0_k
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_l
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_B.Product_a
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_B.tau_g
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_B.x0_a
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_f
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_B.x0_f
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_lw
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_B.Merge3
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_B.TrigonometricFunction1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Control_Kieran_quanser_imu_B.tau_a
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_B.Sum
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Control_Kieran_quanser_imu_B.Product1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_o
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_B.Sum4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Control_Kieran_quanser_imu_B.Switch2
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Control_Kieran_quanser_imu_B.Merge6
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Control_Kieran_quanser_imu_B.Merge3_e
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Control_Kieran_quanser_imu_B.Merge1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Control_Kieran_quanser_imu_B.Wireonotherside
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Control_Kieran_quanser_imu_B.x0_d
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_kv
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_B.x0_h
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_e
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Control_Kieran_quanser_imu_B.x0_i
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_a
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Control_Kieran_quanser_imu_B.x0_hd
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Control_Kieran_quanser_imu_B.Integrator1_i
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Control_Kieran_quanser_imu_B.Subtract2
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Control_Kieran_quanser_imu_B.MathFunction
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Control_Kieran_quanser_imu_B.Amplitude3
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Control_Kieran_quanser_imu_B.x0_fw
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Control_Kieran_quanser_imu_B.Merge
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Control_Kieran_quanser_imu_B.Sum6
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Control_Kieran_quanser_imu_B.Product_l
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_i
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Control_Kieran_quanser_imu_B.x0_me
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Control_Kieran_quanser_imu_B.Product_a3
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Control_Kieran_quanser_imu_B.x0_fwo
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Control_Kieran_quanser_imu_B.Product_aq
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Control_Kieran_quanser_imu_B.Product_m
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_g
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Control_Kieran_quanser_imu_B.Product_g
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_j
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Control_Kieran_quanser_imu_B.Product_d
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_k
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Control_Kieran_quanser_imu_B.Product_ac
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_l
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Control_Kieran_quanser_imu_B.Product_gt
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_lt
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% Control_Kieran_quanser_imu_B.Product_ll
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_l0
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% Control_Kieran_quanser_imu_B.Product_p
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_lk
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% Control_Kieran_quanser_imu_B.Product_b
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_c
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% Control_Kieran_quanser_imu_B.Product_lj
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% Control_Kieran_quanser_imu_B.Product1_oj
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% Control_Kieran_quanser_imu_B.Add
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% Control_Kieran_quanser_imu_B.Flexor
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% Control_Kieran_quanser_imu_B.Extensor
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% Control_Kieran_quanser_imu_B.HILReadAnalog2_o3
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% Control_Kieran_quanser_imu_B.HILReadAnalog2_o4
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% Control_Kieran_quanser_imu_B.Amplitude4
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% Control_Kieran_quanser_imu_B.HILReadAnalog4
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% Control_Kieran_quanser_imu_B.ManualSwitch
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% Control_Kieran_quanser_imu_B.ManualSwitch1
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% Control_Kieran_quanser_imu_B.Merge1_i
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% Control_Kieran_quanser_imu_B.Sum_f
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% Control_Kieran_quanser_imu_B.Product_c
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% Control_Kieran_quanser_imu_B.OutportBufferForOut2
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% Control_Kieran_quanser_imu_B.In1
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_B.HostInitialize_o2
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_B.HostInitialize_o1
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_B.HostSpeechSynthesis1_o2
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_B.Compare
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_B.HostSpeechSynthesis1_o1
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 22;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Control_Kieran_quanser_imu_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_Lock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_State
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.SystemTimebase_PreviousTime
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 48;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 56;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog3_Buffer
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 64;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog1_Buffer
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 65;
	
	  ;% Control_Kieran_quanser_imu_DW.Memory1_PreviousInput
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 66;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog_Buffer
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 67;
	
	  ;% Control_Kieran_quanser_imu_DW.TimeStampA
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 68;
	
	  ;% Control_Kieran_quanser_imu_DW.LastUAtTimeA
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 69;
	
	  ;% Control_Kieran_quanser_imu_DW.TimeStampB
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 70;
	
	  ;% Control_Kieran_quanser_imu_DW.LastUAtTimeB
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 71;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog2_Buffer
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 72;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog4_Buffer
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 76;
	
	  ;% Control_Kieran_quanser_imu_DW.Memory_PreviousInput
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 77;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HostInitialize_ConnectedHandle
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_SendContex
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog3_PWORK
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog1_PWORK
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_DW.LowLvSpeedController_PWORK
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope10_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope11_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope12_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope13_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope14_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope15_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope17_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 35;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadDigital_PWORK
	  section.data(12).logicalSrcIdx = 36;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope18_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 37;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_DW.StringSelect_PWORK.StringTable
	  section.data(14).logicalSrcIdx = 38;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope20_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 39;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope3_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 40;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope4_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 41;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope5_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 42;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope6_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 43;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope8_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 44;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope9_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 45;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile1_PWORK
	  section.data(22).logicalSrcIdx = 46;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile2_PWORK
	  section.data(23).logicalSrcIdx = 47;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile5_PWORK
	  section.data(24).logicalSrcIdx = 48;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_DW.ToWorkspace_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 49;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog_PWORK
	  section.data(26).logicalSrcIdx = 50;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 51;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope1_PWORK_m.LoggedData
	  section.data(28).logicalSrcIdx = 52;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope2_PWORK.LoggedData
	  section.data(29).logicalSrcIdx = 53;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope3_PWORK_k.LoggedData
	  section.data(30).logicalSrcIdx = 54;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope4_PWORK_i.LoggedData
	  section.data(31).logicalSrcIdx = 55;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope_PWORK_n.LoggedData
	  section.data(32).logicalSrcIdx = 56;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope1_PWORK_f.LoggedData
	  section.data(33).logicalSrcIdx = 57;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope14_PWORK_i.LoggedData
	  section.data(34).logicalSrcIdx = 58;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile3_PWORK
	  section.data(35).logicalSrcIdx = 59;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog2_PWORK
	  section.data(36).logicalSrcIdx = 60;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Control_Kieran_quanser_imu_DW.HILReadAnalog4_PWORK
	  section.data(37).logicalSrcIdx = 61;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope2_PWORK_d.LoggedData
	  section.data(38).logicalSrcIdx = 62;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope21_PWORK.LoggedData
	  section.data(39).logicalSrcIdx = 63;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope22_PWORK.LoggedData
	  section.data(40).logicalSrcIdx = 64;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope7_PWORK.LoggedData
	  section.data(41).logicalSrcIdx = 65;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile4_PWORK
	  section.data(42).logicalSrcIdx = 66;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile6_PWORK
	  section.data(43).logicalSrcIdx = 67;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope_PWORK_e.LoggedData
	  section.data(44).logicalSrcIdx = 68;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope1_PWORK_mi.LoggedData
	  section.data(45).logicalSrcIdx = 69;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Control_Kieran_quanser_imu_DW.Scope2_PWORK_dt.LoggedData
	  section.data(46).logicalSrcIdx = 70;
	  section.data(46).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 73;
	  section.data(3).dtTransOffset = 19;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 74;
	  section.data(4).dtTransOffset = 27;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 75;
	  section.data(5).dtTransOffset = 35;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 76;
	  section.data(6).dtTransOffset = 43;
	
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 77;
	  section.data(7).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK.IcNeedsLoading
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_m.IcNeedsLoading
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_j.IcNeedsLoading
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_i.IcNeedsLoading
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_k.IcNeedsLoading
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_c.IcNeedsLoading
	  section.data(6).logicalSrcIdx = 84;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_l.IcNeedsLoading
	  section.data(7).logicalSrcIdx = 85;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_ct.IcNeedsLoading
	  section.data(8).logicalSrcIdx = 86;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_o.IcNeedsLoading
	  section.data(9).logicalSrcIdx = 87;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_n.IcNeedsLoading
	  section.data(10).logicalSrcIdx = 88;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_DW.Texttospeak1_IWORK
	  section.data(11).logicalSrcIdx = 89;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile1_IWORK
	  section.data(12).logicalSrcIdx = 90;
	  section.data(12).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile2_IWORK
	  section.data(13).logicalSrcIdx = 91;
	  section.data(13).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile5_IWORK
	  section.data(14).logicalSrcIdx = 92;
	  section.data(14).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_g.IcNeedsLoading
	  section.data(15).logicalSrcIdx = 93;
	  section.data(15).dtTransOffset = 21;
	
	  ;% Control_Kieran_quanser_imu_DW.Integrator1_IWORK_b.IcNeedsLoading
	  section.data(16).logicalSrcIdx = 94;
	  section.data(16).dtTransOffset = 22;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile3_IWORK
	  section.data(17).logicalSrcIdx = 95;
	  section.data(17).dtTransOffset = 23;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile4_IWORK
	  section.data(18).logicalSrcIdx = 96;
	  section.data(18).dtTransOffset = 26;
	
	  ;% Control_Kieran_quanser_imu_DW.ToHostFile6_IWORK
	  section.data(19).logicalSrcIdx = 97;
	  section.data(19).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem3_SubsysRanBC
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Control_Kieran_quanser_imu_DW.If7_ActiveSubsystem
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem
	  section.data(4).logicalSrcIdx = 101;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem5_SubsysRanBC
	  section.data(5).logicalSrcIdx = 102;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem6_SubsysRanBC
	  section.data(6).logicalSrcIdx = 103;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Control_Kieran_quanser_imu_DW.If5_ActiveSubsystem
	  section.data(7).logicalSrcIdx = 104;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem13_SubsysRanBC
	  section.data(8).logicalSrcIdx = 105;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Control_Kieran_quanser_imu_DW.If2_ActiveSubsystem_c
	  section.data(9).logicalSrcIdx = 106;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Control_Kieran_quanser_imu_DW.If1_ActiveSubsystem_e
	  section.data(10).logicalSrcIdx = 107;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(11).logicalSrcIdx = 108;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Control_Kieran_quanser_imu_DW.EnabledSubsystem_SubsysRanBC
	  section.data(12).logicalSrcIdx = 109;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Control_Kieran_quanser_imu_DW.If_ActiveSubsystem
	  section.data(13).logicalSrcIdx = 110;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC
	  section.data(14).logicalSrcIdx = 111;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(15).logicalSrcIdx = 112;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Control_Kieran_quanser_imu_DW.If_end_signal_ActiveSubsystem
	  section.data(16).logicalSrcIdx = 113;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Control_Kieran_quanser_imu_DW.Outputs1_SubsysRanBC
	  section.data(17).logicalSrcIdx = 114;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Control_Kieran_quanser_imu_DW.Outputs2_SubsysRanBC
	  section.data(18).logicalSrcIdx = 115;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Control_Kieran_quanser_imu_DW.If_ActiveSubsystem_m
	  section.data(19).logicalSrcIdx = 116;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem_SubsysRanBC_o
	  section.data(20).logicalSrcIdx = 117;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 118;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Control_Kieran_quanser_imu_DW.HostSpeechSynthesis1_PreviousSt
	  section.data(2).logicalSrcIdx = 119;
	  section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.HILReadDigital_Buffer
	  section.data(1).logicalSrcIdx = 120;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 121;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem15.IfActionSubsystem14_SubsysRanBC
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem14.IfActionSubsystem14_SubsysRanBC
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem3_p.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem12.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 125;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem6_k.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem5_e.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Control_Kieran_quanser_imu_DW.IfActionSubsystem2.IfActionSubsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3316064542;
  targMap.checksum1 = 1339131345;
  targMap.checksum2 = 3388183172;
  targMap.checksum3 = 2815659602;

