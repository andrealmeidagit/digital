  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (identifica_ip02_P)
    ;%
      section.nData     = 65;
      section.data(65)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_ip02_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_ip02_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_ip02_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_ip02_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_ip02_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_ip02_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_ip02_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_ip02_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_ip02_P.HILInitialize_AOWatchdog
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_ip02_P.HILInitialize_POFrequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_ip02_P.HILInitialize_POLeading
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_ip02_P.HILInitialize_POTrailing
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_ip02_P.HILInitialize_POInitial
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_ip02_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_ip02_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_ip02_P.Conversiontom_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_ip02_P.Constant_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_ip02_P.Conversiontord_Gain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% identifica_ip02_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% identifica_ip02_P.mtomm_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% identifica_ip02_P.Definesinaldeentrada_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% identifica_ip02_P.SquareWave_Amplitude
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% identifica_ip02_P.SquareWave_Frequency
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% identifica_ip02_P.LookUpTable_XData
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% identifica_ip02_P.LookUpTable_YData
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 31;
	
	  ;% identifica_ip02_P.Amplitude_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% identifica_ip02_P.RateLimiter_RisingLim
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% identifica_ip02_P.RateLimiter_FallingLim
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 39;
	
	  ;% identifica_ip02_P.Step_Time
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 40;
	
	  ;% identifica_ip02_P.Step_Y0
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 41;
	
	  ;% identifica_ip02_P.Step_YFinal
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 42;
	
	  ;% identifica_ip02_P.mmtom_Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 43;
	
	  ;% identifica_ip02_P.Kp_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 44;
	
	  ;% identifica_ip02_P.AmplifierVoltageLimit_UpperSat
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 45;
	
	  ;% identifica_ip02_P.AmplifierVoltageLimit_LowerSat
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 46;
	
	  ;% identifica_ip02_P.CableGainPreCompensation_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 47;
	
	  ;% identifica_ip02_P.DACLimit_UpperSat
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 48;
	
	  ;% identifica_ip02_P.DACLimit_LowerSat
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 49;
	
	  ;% identifica_ip02_P.CableGain_Gain
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 50;
	
	  ;% identifica_ip02_P.mtomm_Gain_h
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 51;
	
	  ;% identifica_ip02_P.mtomm_Gain_f
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 52;
	
	  ;% identifica_ip02_P.VelocidadeparaPosio_IC
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 53;
	
	  ;% identifica_ip02_P.mtomm_Gain_b
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 54;
	
	  ;% identifica_ip02_P.IP02ModeloExperimental_A
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 55;
	
	  ;% identifica_ip02_P.IP02ModeloExperimental_C
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 57;
	
	  ;% identifica_ip02_P.Kp1_Gain
	  section.data(48).logicalSrcIdx = 49;
	  section.data(48).dtTransOffset = 59;
	
	  ;% identifica_ip02_P.AmplifierVoltageSaturation_Uppe
	  section.data(49).logicalSrcIdx = 50;
	  section.data(49).dtTransOffset = 60;
	
	  ;% identifica_ip02_P.AmplifierVoltageSaturation_Lowe
	  section.data(50).logicalSrcIdx = 51;
	  section.data(50).dtTransOffset = 61;
	
	  ;% identifica_ip02_P.AmplifierVoltageSaturation1_Upp
	  section.data(51).logicalSrcIdx = 52;
	  section.data(51).dtTransOffset = 62;
	
	  ;% identifica_ip02_P.AmplifierVoltageSaturation1_Low
	  section.data(52).logicalSrcIdx = 53;
	  section.data(52).dtTransOffset = 63;
	
	  ;% identifica_ip02_P.AceleraoparaVelocidade_IC
	  section.data(53).logicalSrcIdx = 54;
	  section.data(53).dtTransOffset = 64;
	
	  ;% identifica_ip02_P.Amortecimentoviscoso_Gain
	  section.data(54).logicalSrcIdx = 55;
	  section.data(54).dtTransOffset = 65;
	
	  ;% identifica_ip02_P.BackEMF1_Gain
	  section.data(55).logicalSrcIdx = 56;
	  section.data(55).dtTransOffset = 66;
	
	  ;% identifica_ip02_P.ForaContraeletromotriz_Gain
	  section.data(56).logicalSrcIdx = 57;
	  section.data(56).dtTransOffset = 67;
	
	  ;% identifica_ip02_P.TensoparaCorrente_Gain
	  section.data(57).logicalSrcIdx = 58;
	  section.data(57).dtTransOffset = 68;
	
	  ;% identifica_ip02_P.SaturaoparaCorrente_UpperSat
	  section.data(58).logicalSrcIdx = 59;
	  section.data(58).dtTransOffset = 69;
	
	  ;% identifica_ip02_P.SaturaoparaCorrente_LowerSat
	  section.data(59).logicalSrcIdx = 60;
	  section.data(59).dtTransOffset = 70;
	
	  ;% identifica_ip02_P.CorrenteparaFora_Gain
	  section.data(60).logicalSrcIdx = 61;
	  section.data(60).dtTransOffset = 71;
	
	  ;% identifica_ip02_P.Inercias_Gain
	  section.data(61).logicalSrcIdx = 62;
	  section.data(61).dtTransOffset = 72;
	
	  ;% identifica_ip02_P.StepAmplitude_Gain
	  section.data(62).logicalSrcIdx = 63;
	  section.data(62).dtTransOffset = 73;
	
	  ;% identifica_ip02_P.StepAmplitude_Gain_f
	  section.data(63).logicalSrcIdx = 64;
	  section.data(63).dtTransOffset = 74;
	
	  ;% identifica_ip02_P.XMAX_Value
	  section.data(64).logicalSrcIdx = 65;
	  section.data(64).dtTransOffset = 75;
	
	  ;% identifica_ip02_P.XIN_Value
	  section.data(65).logicalSrcIdx = 66;
	  section.data(65).dtTransOffset = 76;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 3;
	
	  ;% identifica_ip02_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 4;
	
	  ;% identifica_ip02_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 5;
	
	  ;% identifica_ip02_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 6;
	
	  ;% identifica_ip02_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 7;
	
	  ;% identifica_ip02_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 8;
	
	  ;% identifica_ip02_P.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 8;
	
	  ;% identifica_ip02_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 16;
	
	  ;% identifica_ip02_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 78;
	  section.data(4).dtTransOffset = 24;
	
	  ;% identifica_ip02_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 79;
	  section.data(5).dtTransOffset = 32;
	
	  ;% identifica_ip02_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 80;
	  section.data(6).dtTransOffset = 33;
	
	  ;% identifica_ip02_P.EncoderInput0CartPositionEnco_l
	  section.data(7).logicalSrcIdx = 81;
	  section.data(7).dtTransOffset = 41;
	
	  ;% identifica_ip02_P.EncoderInput0CartPositionEnco_a
	  section.data(8).logicalSrcIdx = 82;
	  section.data(8).dtTransOffset = 43;
	
	  ;% identifica_ip02_P.AnalogOutput0ToAmplifierDriving
	  section.data(9).logicalSrcIdx = 83;
	  section.data(9).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.ShowMessageonHost_MsgIcon
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.ShowMessageonHost_MsgIcon_b
	  section.data(2).logicalSrcIdx = 85;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.SwitchControl_Threshold
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_ip02_P.Constant_Value_p
	  section.data(3).logicalSrcIdx = 88;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_ip02_P.SwitchControl_Threshold_d
	  section.data(4).logicalSrcIdx = 89;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% identifica_ip02_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_ip02_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_ip02_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_ip02_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_ip02_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_ip02_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 96;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_ip02_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 97;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_ip02_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 98;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_ip02_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 99;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_ip02_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 100;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_ip02_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 101;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_ip02_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 102;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_ip02_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 103;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_ip02_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 104;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_ip02_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 105;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_ip02_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 106;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_ip02_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 107;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_ip02_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 108;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_ip02_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 109;
	  section.data(20).dtTransOffset = 19;
	
	  ;% identifica_ip02_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 110;
	  section.data(21).dtTransOffset = 20;
	
	  ;% identifica_ip02_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 111;
	  section.data(22).dtTransOffset = 21;
	
	  ;% identifica_ip02_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 112;
	  section.data(23).dtTransOffset = 22;
	
	  ;% identifica_ip02_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 113;
	  section.data(24).dtTransOffset = 23;
	
	  ;% identifica_ip02_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 114;
	  section.data(25).dtTransOffset = 24;
	
	  ;% identifica_ip02_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 115;
	  section.data(26).dtTransOffset = 25;
	
	  ;% identifica_ip02_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 116;
	  section.data(27).dtTransOffset = 26;
	
	  ;% identifica_ip02_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 117;
	  section.data(28).dtTransOffset = 27;
	
	  ;% identifica_ip02_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 118;
	  section.data(29).dtTransOffset = 28;
	
	  ;% identifica_ip02_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 119;
	  section.data(30).dtTransOffset = 29;
	
	  ;% identifica_ip02_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 120;
	  section.data(31).dtTransOffset = 30;
	
	  ;% identifica_ip02_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 121;
	  section.data(32).dtTransOffset = 31;
	
	  ;% identifica_ip02_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 122;
	  section.data(33).dtTransOffset = 32;
	
	  ;% identifica_ip02_P.EncoderInput0CartPositionEnco_f
	  section.data(34).logicalSrcIdx = 123;
	  section.data(34).dtTransOffset = 33;
	
	  ;% identifica_ip02_P.AnalogOutput0ToAmplifierDrivi_m
	  section.data(35).logicalSrcIdx = 124;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (identifica_ip02_B)
    ;%
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% identifica_ip02_B.EncoderInput0CartPositionEncode
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_B.EncoderInput0CartPositionEnco_n
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_ip02_B.Conversiontom
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_ip02_B.Conversiontord
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_ip02_B.Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_ip02_B.mtomm
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% identifica_ip02_B.SquareWave
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% identifica_ip02_B.Clock
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% identifica_ip02_B.Fcn1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% identifica_ip02_B.LookUpTable
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% identifica_ip02_B.Amplitude
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% identifica_ip02_B.RateLimiter
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% identifica_ip02_B.Step
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% identifica_ip02_B.MultiportSwitch
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% identifica_ip02_B.mmtom
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% identifica_ip02_B.Sum4
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% identifica_ip02_B.Kp
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% identifica_ip02_B.AmplifierVoltageLimit
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% identifica_ip02_B.CableGainPreCompensation
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% identifica_ip02_B.DACLimit
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% identifica_ip02_B.CableGain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% identifica_ip02_B.mtomm_l
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% identifica_ip02_B.mtomm_k
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% identifica_ip02_B.VelocidadeparaPosio
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% identifica_ip02_B.mtomm_m
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% identifica_ip02_B.IP02ModeloExperimental
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% identifica_ip02_B.SwitchControl
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% identifica_ip02_B.Sum2
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% identifica_ip02_B.Kp1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% identifica_ip02_B.AmplifierVoltageSaturation
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% identifica_ip02_B.SwitchControl_d
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% identifica_ip02_B.AmplifierVoltageSaturation1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% identifica_ip02_B.AceleraoparaVelocidade
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% identifica_ip02_B.Amortecimentoviscoso
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% identifica_ip02_B.BackEMF1
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% identifica_ip02_B.ForaContraeletromotriz
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% identifica_ip02_B.Sum
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% identifica_ip02_B.TensoparaCorrente
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% identifica_ip02_B.SaturaoparaCorrente
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% identifica_ip02_B.CorrenteparaFora
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% identifica_ip02_B.Sum1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% identifica_ip02_B.Inercias
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% identifica_ip02_B.CheckMaximumAllowedPosition
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% identifica_ip02_B.CheckMinimumAllowedPosition
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% identifica_ip02_B.StepAmplitude
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% identifica_ip02_B.StepAmplitude_d
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% identifica_ip02_B.Compare
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_B.Compare_m
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 2;
    
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
    ;% Auto data (identifica_ip02_DWork)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% identifica_ip02_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% identifica_ip02_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% identifica_ip02_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% identifica_ip02_DWork.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% identifica_ip02_DWork.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% identifica_ip02_DWork.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% identifica_ip02_DWork.PrevY
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% identifica_ip02_DWork.LastMajorTime
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.AnalogOutput0ToAmplifierDriving
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_DWork.VCommandV_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% identifica_ip02_DWork.ScopeRealvsTeorico_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% identifica_ip02_DWork.ToWorkspaceModeloExperimental_P.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% identifica_ip02_DWork.ToWorkspaceModeloTeorico_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% identifica_ip02_DWork.ToWorkspaceSistemaReal_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% identifica_ip02_DWork.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 3;
	
	  ;% identifica_ip02_DWork.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 11;
	
	  ;% identifica_ip02_DWork.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 19;
	
	  ;% identifica_ip02_DWork.HILInitialize_POModeValues
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 27;
	
	  ;% identifica_ip02_DWork.HILInitialize_POAlignValues
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 35;
	
	  ;% identifica_ip02_DWork.HILInitialize_POPolarityVals
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 43;
	
	  ;% identifica_ip02_DWork.EncoderInput0CartPositionEncode
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.EncoderInput0CartPositionEnco_m
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.CartPositionWatchdog_MODE
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.CartPositionWatchdog_SubsysRanB
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% identifica_ip02_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 106978244;
  targMap.checksum1 = 4086785444;
  targMap.checksum2 = 2202432667;
  targMap.checksum3 = 2367469696;

