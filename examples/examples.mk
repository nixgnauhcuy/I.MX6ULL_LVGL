override CFLAGS := -I$(EXAMPLE_DIR) $(CFLAGS)

CSRCS += $(shell find -L $(EXAMPLE_DIR)/$(EXAMPLE_TRAGE) -name "*.c")
