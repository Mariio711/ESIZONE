do{
                c=fgetc(archivo);
                if(num_guion==0 && c!='-' && c!=EOF)
                    descuentos.id_descuento[i]=c;//id_descuento
                if(num_guion==1 && c!='-' && c!=EOF)
                    descuentos.descripcion[i]=c;//descripcion
                if(num_guion==2 && c!='-' && c!=EOF)
                    descuentos.tipo[i]=c;//tipo
                if(num_guion==3 && c!='-' && c!=EOF)
                    descuentos.estado=c;//estado
                if(num_guion==4 && c!='-' && c!=EOF)
                    importeaux[i]=c;//importe
                if(num_guion==5 && c!='-' && c!=EOF && c!='\n')
                    descuentos.aplicabilidad[i]=c;//aplicabilidad
                if(c=='-'){
                    num_guion++;
                    i=-1;
                }
                if(c=='\n' || c==EOF){
                    num_guion=0;
                    i=-1;
                }
                i++;
                if((c=='\n' || c==EOF) && descuentos.estado=='S'){
                    j=0;
                    do{
                        c2=fgetc(archivo2);
                        
                        if(num_guion2==0 && c2!='-' && c2!=EOF)
                            idaux[j]=c2;//id cliente
                        if(num_guion2==1 && c2!='-' && c2!=EOF)
                            descliente.id_descuento[j]=c2;//id_descuento
                        if(num_guion2==2 && c2!='-' && c2!=EOF)
                            descliente.fecha_inicial[j]=c2;//fecha inicial---------------------------------------------------
                        if(num_guion2==3 && c2!='-' && c2!=EOF)
                            descliente.fecha_limite[j]=c2;//fecha limite
                        if(num_guion2==4 && c2!='-' && c2!=EOF && c2!='\n')
                            descliente.estado=c2;//estado
                        if(c2=='-'){
                            num_guion2++;
                            j=-1;
                        }
                        if(c2=='\n' || c2==EOF){
                            num_guion2=0;
                            j=-1;
                            
                        }
                        j++;
                        if(c2==EOF)
                            rewind(archivo2);
                        if(c2=='\n' && cliente->id==atoi(idaux) && (strcmp(descliente.id_descuento,descuentos.id_descuento)==0) && descliente.estado=='S'){
                            descliente.id=atoi(idaux);
                            descuentos.importe=atof(importeaux);
                            printf("\n%i-%s:",k,descuentos.tipo);
                            printf("\ndescripcion: %s",descuentos.descripcion);
                            printf("\ndisponible para: %s",descuentos.aplicabilidad);
                            printf("\nfecha inicial: %s",descliente.fecha_inicial);
                            printf("\nfecha limite: %s",descliente.fecha_limite);
                            printf("\ndescuento: %.2f$\n",descuentos.importe);
                            k++;
                            memset(descuentos.id_descuento, 0, 10);
                            memset(descuentos.descripcion, 0, 50);
                            memset(descuentos.tipo, 0, 8);
                            memset(descuentos.aplicabilidad, 0, 10);//vacia para no pillar basura en los vectores
                            memset(importeaux, 0, 10);
                            memset(idaux, 0, 10);
                            memset(descliente.id_descuento, 0, 10);
                            memset(descliente.fecha_inicial, 0, 12);
                            memset(descliente.fecha_limite, 0, 12);
                        }


                    }while(c2!=EOF);
                }
            }while(c!=EOF);
        }
    }
    fclose(archivo);
    fclose(archivo2);
    system("pause");









    do{
                do{
                    c=fgetc(archivo);
                    if(num_guion==0 && c!='-' && c!=EOF)
                        descuentos.id_descuento[i]=c;//id_descuento
                    if(num_guion==1 && c!='-' && c!=EOF)
                        descuentos.descripcion[i]=c;//descripcion
                    if(num_guion==2 && c!='-' && c!=EOF)
                        descuentos.tipo[i]=c;//tipo
                    if(num_guion==3 && c!='-' && c!=EOF)
                        descuentos.estado=c;//estado
                    if(num_guion==4 && c!='-' && c!=EOF)
                        importeaux[i]=c;//importe
                    if(num_guion==5 && c!='-' && c!=EOF && c!='\n')
                        descuentos.aplicabilidad[i]=c;//aplicabilidad
                    if(c=='-'){
                        num_guion++;
                        i=-1;
                    }
                    if(c=='\n' || c==EOF){
                        num_guion=0;
                        i=-1;
                    }
                    i++;
                }while(c!='\n');
                if(descuentos.estado=='S')do{
                    do{
                        c2=fgetc(archivo2);
                        if(num_guion2==0 && c2!='-' && c2!=EOF)
                            idaux[j]=c2;//id cliente
                        if(num_guion2==1 && c2!='-' && c2!=EOF)
                            descliente.id_descuento[j]=c2;//id_descuento
                        if(num_guion2==2 && c2!='-' && c2!=EOF)
                            descliente.fecha_inicial[j]=c2;//fecha inicial---------------------------------------------------
                        if(num_guion2==3 && c2!='-' && c2!=EOF)
                            descliente.fecha_limite[j]=c2;//fecha limite
                        if(num_guion2==4 && c2!='-' && c2!=EOF && c2!='\n')
                            descliente.estado=c2;//estado
                        if(c2=='-'){
                            num_guion2++;
                            j=-1;
                        }
                        if(c2=='\n' || c2==EOF){
                            num_guion2=0;
                            j=-1;
                        }
                        j++;
                        printf("%c",c2);
                    }while(c2!='\n');
                    if(cliente->id==atoi(idaux) && (strcmp(descliente.id_descuento,descuentos.id_descuento)==0) && descliente.estado=='S'){
                            descliente.id=atoi(idaux);
                            descuentos.importe=atof(importeaux);
                            printf("\n%i-%s:",k,descuentos.tipo);
                            printf("\ndescripcion: %s",descuentos.descripcion);
                            printf("\ndisponible para: %s",descuentos.aplicabilidad);
                            printf("\nfecha inicial: %s",descliente.fecha_inicial);
                            printf("\nfecha limite: %s",descliente.fecha_limite);
                            printf("\ndescuento: %.2f$\n",descuentos.importe);
                            k++;
                            memset(descuentos.id_descuento, 0, 10);
                            memset(descuentos.descripcion, 0, 50);
                            memset(descuentos.tipo, 0, 8);
                            memset(descuentos.aplicabilidad, 0, 10);//vacia para no pillar basura en los vectores
                            memset(importeaux, 0, 10);
                            memset(idaux, 0, 10);
                            memset(descliente.id_descuento, 0, 10);
                            memset(descliente.fecha_inicial, 0, 12);
                            memset(descliente.fecha_limite, 0, 12);
                    }
                }while(c2!=EOF);
                rewind(archivo2);

            }while(c!=EOF);
        }
    }
    fclose(archivo);
    fclose(archivo2);
    system("pause");