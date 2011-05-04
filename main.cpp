#include<sample.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<omp.h>

bool cube_separation_oracle(point);
bool sphere_separation_oracle(point);

int main(int argc, char** argv) {
	int ndims = 6;
	int nsamples = 1000;
	int niter = 1000;
	for(int i = 1; i<argc; i++) {
		if(!strcmp(argv[i],"-i")) {
			if(i+1 < argc)
			sscanf(argv[i+1],"%d",&niter);
		}
		if(!strcmp(argv[i],"-s")) {
			if(i+1 < argc)
			sscanf(argv[i+1],"%d",&nsamples);
		}
	}
	int dims[] = {2,3,4,7,10,100};
	char fname[20];
	//cubes with warm start
	for(int i = 0; i<ndims; i++) {
		sprintf(fname,"cube%d_warm",dims[i]);
		printf("Working on cube of dimension %d with a warm start\n",dims[i]);
		point **sample;
		sample = new point*[nsamples];
		for(int j = 0; j<nsamples; j++) {
			sample[j] = new point(dims[i]);
			(*sample[j]) = random_sample(*sample[j],cube_separation_oracle,niter);
		}
		FILE *fout = fopen(fname,"w");
		for(int j = 0; j<nsamples; j++) {
			fprintf(fout,"%lf",sample[j]->x[0]);
			for(int k = 1; k<dims[i]; k++) {
				fprintf(fout," %lf",sample[j]->x[k]);
			}
			fprintf(fout,"\n");
		}
		fclose(fout);
	}
	//cubes with cold start
	for(int i = 0; i<ndims; i++) {
		sprintf(fname,"cube%d_cold",dims[i]);
		printf("Working on cube of dimension %d with a cold start\n",dims[i]);
		point **sample;
		sample = new point*[nsamples];
		for(int j = 0; j<nsamples; j++) {
			sample[j] = new point(dims[i]);
			for(int k = 0; k<dims[i]; k++) {
				sample[j]->x[k] = 1-1e-4;
			}
			(*sample[j]) = random_sample(*sample[j],cube_separation_oracle,niter);
		}
		FILE *fout = fopen(fname,"w");
		for(int j = 0; j<nsamples; j++) {
			fprintf(fout,"%lf",sample[j]->x[0]);
			for(int k = 1; k<dims[i]; k++) {
				fprintf(fout," %lf",sample[j]->x[k]);
			}
			fprintf(fout,"\n");
		}
		fclose(fout);
	}
	//spheres with warm start
	for(int i = 0; i<ndims; i++) {
		sprintf(fname,"sphere%d_warm",dims[i]);
		printf("Working on sphere of dimension %d with a warm start\n",dims[i]);
		point **sample;
		sample = new point*[nsamples];
		for(int j = 0; j<nsamples; j++) {
			sample[j] = new point(dims[i]);
			(*sample[j]) = random_sample(*sample[j],sphere_separation_oracle,niter);
		}
		FILE *fout = fopen(fname,"w");
		for(int j = 0; j<nsamples; j++) {
			fprintf(fout,"%lf",sample[j]->x[0]);
			for(int k = 1; k<dims[i]; k++) {
				fprintf(fout," %lf",sample[j]->x[k]);
			}
			fprintf(fout,"\n");
		}
		fclose(fout);
	}
	//spheres with cold start
	for(int i = 0; i<ndims; i++) {
		sprintf(fname,"sphere%d_cold",dims[i]);
		printf("Working on sphere of dimension %d with a cold start\n",dims[i]);
		point **sample;
		sample = new point*[nsamples];
		for(int j = 0; j<nsamples; j++) {
			sample[j] = new point(dims[i]);
			sample[j]->x[0] = 1-1e-4;
			(*sample[j]) = random_sample(*sample[j],sphere_separation_oracle,niter);
		}
		FILE *fout = fopen(fname,"w");
		for(int j = 0; j<nsamples; j++) {
			fprintf(fout,"%lf",sample[j]->x[0]);
			for(int k = 1; k<dims[i]; k++) {
				fprintf(fout," %lf",sample[j]->x[k]);
			}
			fprintf(fout,"\n");
		}
		fclose(fout);
	}
	return 0;
}

bool cube_separation_oracle(point p) {
	for(int i = 0; i<p.n; i++) {
		if(p.x[i] <= -1 || p.x[i] >= 1) return false;
	}
	return true;
}

bool sphere_separation_oracle(point p) {
	real square_norm = 0.0;
	for(int i = 0; i<p.n; i++) {
		square_norm += p.x[i] * p.x[i];
	}
	return square_norm < 1.0;
}
