#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void statistica(FILE *f){
  int contor_mov=0, contor_arit=0, contor_jmp=0, contor_other=0;
  char *aux,*a="\tadd",*s="\tsub",*i="\tinc",*d="\tdec",*m="\tmul",*im="\timu",*di="\tdiv",*id="\tidi";
  size_t len = 0;
  ssize_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, f)) != -1) {
    aux="\tmov";
    if((strncmp(line,aux,4))==0){
      contor_mov++;
    }
    else{
      aux="\tjmp";
      if((strncmp(line,aux,4))==0){
        contor_jmp++;
      }
      else{
          if((strncmp(line,a,4))==0 || ((strncmp(line,s,4))==0) || ((strncmp(line,i,4))==0) || ((strncmp(line,d,4))==0) || ((strncmp(line,m,4))==0) || ((strncmp(line,im,4))==0) || ((strncmp(line,di,4))==0) || ((strncmp(line,id,4))==0)){
            contor_arit++;
          }
          else{
            contor_other++;
          }
        }
      }
    }
    printf("Contor mov: %d\n", contor_mov);
    printf("Contor arit: %d\n", contor_arit);
    printf("Contor jmp: %d\n", contor_jmp);
    printf("Contor oth: %d\n", contor_other);
    printf("\n");
 // fseek(out,0,SEEK_END);
 // fprintf(out,"%s : %d","Contor mov", contor_mov);
//  fprintf(out,"%s : %d","Contor arit", contor_arit);
//  fprintf(out,"%s : %d","Contor jmp", contor_jmp);
//  fprintf(out,"%s : %d","Contor other", contor_other);
//  fclose(out);
}
void main(){
  system("gcc -S lab2_1.c");
  system("gcc -S lab2_2.c");
  FILE *lab2_1 = fopen("lab2_1.s","r");
  if (!lab2_1){
    printf("Eroare la primul fisier\n");
    exit(1);
  }
  FILE *lab2_2 = fopen("lab2_2.s","r");
  if(!lab2_2){
    printf("Eroare la al doi-lea fisier\n");
  }
  statistica(lab2_1);
  statistica(lab2_2);
  fclose(lab2_1);
  fclose(lab2_2);
}