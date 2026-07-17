graph TD
    subgraph "Input Processing"
    Input[Raw Data] --> PM[Pipeline Manager]
    end

    subgraph "Transformation Pipeline (ChaosLayer)"
    PM --> S1[Stage 1: Obfuscator A]
    S1 --> S2[Stage 2: Obfuscator B]
    S2 --> Sn[Stage N: Obfuscator N]
    end

    subgraph "Output"
    Sn --> Output[Obfuscated/Chaotic Data]
    end

    subgraph "Restoration Path"
    Output --> RPM[Reverse Pipeline Manager]
    RPM --> RSn[Reverse Stage N]
    RSn --> RS2[Reverse Stage B]
    RS2 --> RS1[Reverse Stage A]
    RS1 --> Restored[Original Data]
    end


......work_cod///////
    graph TD
    %% Input Section
    subgraph "Input Processing"
        Input[Raw Data: Struct/File/Buffer] --> PM[Pipeline Manager]
    end

    %% Transformation Pipeline
    subgraph "Transformation Pipeline (ChaosLayer)"
        PM --> S1[Stage 1: Byte Manipulation]
        S1 --> S2[Stage 2: Bitwise Rotation]
        S2 --> Sn[Stage N: Complex Transposition]
    end

    %% Final Output
    subgraph "Final Output"
        Sn --> Output[Obfuscated: Chaotic Binary Data]
    end

    %% Restoration Path
    subgraph "Restoration Path"
        Output --> RPM[Reverse Pipeline Manager]
        RPM --> RSn[Reverse Stage N]
        RSn --> RS2[Reverse Stage B]
        RS2 --> RS1[Reverse Stage A]
        RS1 --> Restored[Original Data Recovered]
    end

    %% Styling
    style Input fill:#f9f,stroke:#333
    style Output fill:#ff9,stroke:#333
    style Restored fill:#9f9,stroke:#333
