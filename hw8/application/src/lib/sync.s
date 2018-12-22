  /* 
   * This is an atomic operation defined in 
   * https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
   * page 42.
   * */ 
.globl compare_and_swap;
.globl fetch_and_add;

compare_and_swap:
   # a0 holds address of memory location
   # a1 holds expected value
   # a2 holds desired value
   # a0 holds return value, 0 if successful, !0 otherwise
   lr.w t0, (a0)        # Load original value.
   bne t0, a1, fail     # Does not match, so fail.
   sc.w a0, a2, (a0)    # Try to update.
   jr ra                # Return.
fail:
   li a0, 1             # Set return to failure.
   jr ra                # Return.

fetch_and_add:
   # a0 holds address of memory location
   # a1 holds appended value
   lr.w t0, (a0)        # Load original value.
   add t1, t0, a1       # make t0 = a1 + a0
   sc.w a0, t1, (a0)    # Try to update.
   mv a0, t0            # Set return
   jr ra                # Return.
