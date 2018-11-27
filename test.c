
#include<stdio.h>
#include <mpi.h> 
int main(){

	int rank, size;
	int buf_1=2,buf_2;
	//MPI_Init(&argc,&argv);
	MPI_Init(0,0);
	MPI_Request status;	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	//printf("hello from %d\n",rank);
	//if(rank==0)
	//{

	//	printf("parameter number is %d\n",argc);
	//	printf("excutable name =%s\n",argv[0]);
	//	printf("velocity name =%s\n",argv[1]);
	//	printf("Nx=%d\n",atoi(argv[2]));
	//	printf("Nz=%d\n",atoi(argv[3]));
	//}
	if(rank == 0){
		printf("rank0 =%d ,%d\n",rank,buf_1);
		buf_1 = 1;
		//printf("%d\n",buf_1);
		MPI_Send(&buf_1, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		//printf("%d:%d\n",rank, buf_1); 
		printf("%d\n",rank); 

	}

	if(rank == 1){ 
		printf("rank1 =%d ,%d\n",rank,buf_1);
		MPI_Recv(&buf_1, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		printf("%d\n",rank); 
		//printf("request =%d\n",status)
		}
	MPI_Finalize();
	return 0;
}
