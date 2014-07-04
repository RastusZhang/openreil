
#ifndef _REIL_IR_H_
#define _REIL_IR_H_

#define REIL_MAX_NAME_LEN 15

#define IOPT_CALL       0x00000001
#define IOPT_RET        0x00000002
#define IOPT_BB_END     0x00000004
#define IOPT_ASM_END    0x00000008

typedef enum _reil_op_t 
{ 
    I_NONE,
    I_JCC,      // conditional jump 
    I_STR,      // store value to register
    I_STM,      // store value to memory
    I_LDM,      // load value from memory
    I_ADD,      // addition
    I_SUB,      // substraction
    I_NEG,      // negation
    I_MUL,      // multiplication
    I_DIV,      // division
    I_MOD,      // modulus    
    I_SMUL,     // signed multiplication
    I_SDIV,     // signed division
    I_SMOD,     // signed modulus
    I_SHL,      // shift left
    I_SHR,      // shift right
    I_ROL,      // rotate left
    I_ROR,      // rotate right
    I_AND,      // binary and
    I_OR,       // binary or
    I_XOR,      // binary xor
    I_NOT,      // binary not  
    I_EQ,       // equation
    I_NEQ,      // equation
    I_L,        // less than
    I_LE,       // less or equal than
    I_SL,       // signed less than
    I_SLE,      // signed less or equal than    
    I_LCAST,    // low half of the integer
    I_HCAST,    // high half of the integer
    I_UCAST,    // cast to unsigned value
    I_SCAST     // cast with sign bit

} reil_op_t;

typedef enum _reil_type_t
{
    A_NONE,
    A_REG,      // target architecture registry operand
    A_TEMP,     // temporary registry operand
    A_CONST     // immediate value

} reil_type_t;

typedef uint64_t reil_const_t;
typedef uint64_t reil_addr_t;
typedef uint16_t reil_inum_t;

typedef enum _reil_size_t { U1, U8, U16, U32, U64 } reil_size_t;

typedef struct _reil_arg_t
{
    reil_type_t type;
    reil_size_t size;        
    reil_const_t val;    
    char name[REIL_MAX_NAME_LEN];

} reil_arg_t;

typedef struct _reil_raw_t
{
    reil_addr_t addr;   // address of the original assembly instruction
    int size;           // .. and it's size

    // pointer to the instruction bytes
    unsigned char *data;

} reil_raw_t;

typedef struct _reil_inst_t
{
    reil_raw_t raw_info;    

    reil_inum_t inum;   // number of the IR subinstruction
    reil_op_t op;       // operation code
    reil_arg_t a, b, c; // arguments
    uint64_t flags;     // options

} reil_inst_t;

#endif
