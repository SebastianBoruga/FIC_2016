#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void statistica(FILE *f){
  int contor_mov=0, contor_arit=0, contor_jmp=0, contor_other=0,i;
  char *aux;
  char **str;
  strcpy(str[0],"\tadd");
  strcpy(str[1],"\tsub");
  strcpy(str[2],"\tinc");
  strcpy(str[3],"\tdec");
  strcpy(str[4],"\tmul");
  strcpy(str[5],"\timu");
  strcpy(str[6],"\tdiv");
  strcpy(str[7],"\tidi");
  size_t len = 0;
  ssize_t read;
  char *line = NULL;
  FILE *out = fopen("out.txt","w");
  while ((read = getline(&line, &len, f)) != -1) {
    char *l;
    strncpy(l,line,4);
    if( (strstr(l,".")!= NULL) ){
      continue;
    } 
    aux="\tmov";
    if((strncmp(line,aux,4))==0){
      contor_mov++;
    }
    else{
      aux="\tj";
      if((strncmp(line,aux,2))==0){
        contor_jmp++;
      }
      else{
          /*if((strncmp(line,a,4))==0 || ((strncmp(line,s,4))==0) || ((strncmp(line,i,4))==0) || ((strncmp(line,d,4))==0) || ((strncmp(line,m,4))==0) || ((strncmp(line,im,4))==0) || ((strncmp(line,di,4))==0) || ((strncmp(line,id,4))==0))*/
          for(i=0;i<8;i++)
          {
          if(strncmp(line,str[i],4)==0)
            contor_arit++;
          
          else{
            contor_other++;
          }
          }
        }
      }
    }


    fprintf(out,"%s : %d\n","Contor mov", contor_mov);
    fprintf(out,"%s : %d\n","Contor arit", contor_arit);
    fprintf(out,"%s : %d\n","Contor jmp", contor_jmp);
    fprintf(out,"%s : %d\n","Contor other", contor_other);
    fclose(out);
}
void main(){
  system("gcc -S l2_1.c");
//  system("gcc -S lab2_2.c");
  FILE *lab2_1 = fopen("l2_1.s","r");
  if (!lab2_1){
    printf("Eroare la primul fisier\n");
    exit(1);
  }
/*  FILE *lab2_2 = fopen("lab2_2.s","r");
  if(!lab2_2){
    printf("Eroare la al doi-lea fisier\n");
  }*/
  statistica(lab2_1);
 // statistica(lab2_2);
  fclose(lab2_1);
//  fclose(lab2_2);
}