#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* suledoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* flagError);

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this,int* flagError);

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* flagError);

int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* flagError);

int employee_setIdArchivo(char* nameFile,int id);
int employee_getIdArchivo(char* nameFile,char* id);

int employee_addIdFree(char* nameFile,char* id);
int employee_printOne(Employee* this);

int employee_CompareByName(void* e1, void* e2);



#endif // employee_H_INCLUDED
