.PHONY: clean All

All:
	@echo "==========Building project:[ aula-01 - Debug ]=========="
	@cd "aula-01" && "$(MAKE)" -f  "aula-01.mk"
clean:
	@echo "==========Cleaning project:[ aula-01 - Debug ]----------"
	@cd "aula-01" && "$(MAKE)" -f  "aula-01.mk" clean
