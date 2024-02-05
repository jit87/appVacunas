.PHONY: clean All

All:
	@echo "----------Building project:[ UOCVaccine - Debug ]----------"
	@cd "UOCVaccine" && "$(MAKE)" -f  "UOCVaccine.mk"
	@echo "----------Building project:[ UOC20212 - Debug ]----------"
	@"$(MAKE)" -f  "UOC20212.mk"
clean:
	@echo "----------Cleaning project:[ UOCVaccine - Debug ]----------"
	@cd "UOCVaccine" && "$(MAKE)" -f  "UOCVaccine.mk"  clean
	@echo "----------Cleaning project:[ UOC20212 - Debug ]----------"
	@"$(MAKE)" -f  "UOC20212.mk" clean
