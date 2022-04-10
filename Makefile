#Which Files are Included in Project
Files = Main.o Units.o Ideal_Gas.o Isentropic.o Shock.o Oblique_Angle_Solver.o LibVar.o Data_Comparison.o Prandtl_Meyer_Expansion_Solver.o Isentropic_CD_Area_Inverse.o

#Compiler Choice
Compiler = gcc

#Compile Flags
Flags = -lm 

#Final Binary
Exec: $(Files)
	@echo "Linking all Object Files"
	@$(Compiler) $(Flags) $(Files) -o Exec

Ideal_Gas.o: Ideal_Gas.c
	@echo "Building Ideal_Gas..."
	@$(Compiler) $(Flags) -o Ideal_Gas.o -c Ideal_Gas.c

Isentropic.o: Isentropic.c
	@echo "Building Isentropic..."
	@$(Compiler) $(Flags) -o Isentropic.o -c Isentropic.c

Shock.o: Shock.c
	@echo "Building Shock..."
	@$(Compiler) $(Flags) -o Shock.o -c Shock.c

Oblique_Angle_Solver.o: Oblique_Angle_Solver.c
	@echo "Building Oblique_Angle_Solver..."
	@$(Compiler) $(Flags) -o Oblique_Angle_Solver.o -c Oblique_Angle_Solver.c

Prandtl_Meyer_Expansion_Solver.o: Prandtl_Meyer_Expansion_Solver.c
	@echo "Building Prandtl_Meyer_Expansion_Solver..."
	@$(Compiler) $(Flags) -o Prandtl_Meyer_Expansion_Solver.o -c Prandtl_Meyer_Expansion_Solver.c

LibVar.o: LibVar.c
	@echo "Building LibVar..."
	@$(Compiler) $(Flags) -o LibVar.o -c LibVar.c

Main.o: Main.c
	@echo "Building Main..."
	@$(Compiler) $(Flags) -o Main.o -c Main.c

Data_Comparison.o: Data_Comparison.c
	@echo "Building Data_Comparison..."
	@$(Compiler) $(Flags) -o Data_Comparison.o -c Data_Comparison.c

Units.o: Units.c
	@echo "Building Units..."
	@$(Compiler) $(Flags) -o Units.o -c Units.c

Isentropic_CD_Area_Inverse.o: Isentropic_CD_Area_Inverse.c
	@echo "Building Isentropic_CD_Area_Inverse..."
	@$(Compiler) $(Flags) -o Isentropic_CD_Area_Inverse.o -c Isentropic_CD_Area_Inverse.c

#sub.o: sub.c
#	@echo "Building sub..."
#	@$(Compiler) $(Flags) -o sub.o -c sub.c

clean:
	@echo "Removing Build Relics"
	@rm *.o *.bin
