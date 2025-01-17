date: 2025-2-17
Function:thermodynamics, soft spheres  based on pr_04_01
Calling list
pr_04_1 (main)
	GetNameList(.c)
	PrintNameList(.c)
	SetParams(.c)
	SetupJob(.c)
		AllocArray(.c)
		InitRand(Rand.c)
		InitCoords(.c)
		InitVels(.c)
		InitAccels(.c)
		AccumProps(.c)
	SingleStep(.c)
  		LeapfrogStep (1);
  		ApplyBoundaryCond ();
		BuildNebrList(.c)
  		ComputeForces ();
		AdjustInitTemp(.c)
		EvalProps(.c)
		AccumProps(.c)
		PrintSummary(.c)
Other functions:
	macros.c (definiations of macros)
	types.c(definiation of data types)
	variables(declare of extern variables)
	initializer.h(initialization of external variables)
	functions.c(declare of functions)
	Rand.c(defination of three functions: 
		InitRand()
		RandR()
		VRand()
