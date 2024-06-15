int s21_sscanf(const char *str, const char *format, ...) {
    int res = 0;
    va_list parameters;
    va_start(parameters, format);


    while(*format && *str) {
        if(*format == '%') {
            format++;
            Variable v = {0};
            format = get_specifier(format, &v);
            str = set_value(str, parameters, &v);
            res += v.res;
        } else if (isspace(*format)) {      
            if(isspace(*str))
                str++;
            format++;
        }
    }
    va_end(parameters);
    return res;
}

const char *get_specifier(const char *ptr, Variable *v) {
    char *specifiers = "dscixXuof";
    if(*ptr == '*') {
        v->skip = 1;
        ptr++;
    }
    if(isdigit(*ptr)) {
        int w = 0;
        while(isdigit(*ptr)) {
            w = w * 10 + (*ptr - '0');
            ptr++;
        }
        v->width = w;
    } else {
        v->width = -1;
    }
    if(isalpha(*ptr) && strchr(specifiers, *ptr)) {
        v->spec = *ptr;
        ptr++;            
    }
        
    return ptr;
}

const char *set_value(const char *ptr, va_list parameters, Variable *v) {
    const char *hex_symb = "xXaAbBcCdDeEfF";

    switch (v->spec) {
        case 'd':
        case 'i':            
            if(!v->skip) {
                ptr = set_signed_int(ptr, parameters, v, hex_symb);
            } else {
                if(*ptr == '-') {                    
                    ptr++;
                } 
                while(isdigit(*ptr) || strchr(hex_symb, *ptr))
                    ptr++;
            }             
            break; 
        case 'x':
        case 'X':
        case 'u':
        case 'o':            
            if(!v->skip) {
                ptr = set_unsigned_int(ptr, parameters, v, hex_symb);
            } else {                 
                while(isdigit(*ptr) || strchr(hex_symb, *ptr))
                    ptr++;
            }             
            break; 
        case 'f':
            if(!v->skip) {
                float *fvar = va_arg(parameters, float*);
                float n = 0.0;
                while(*ptr != '.') {
                    n = (float)n * 10.0 + (float)(*ptr - '0');
                    ptr++;
                }
                ptr++;
                float del = 1.0; 
                while(isdigit(*ptr)) {
                   del *= 10.0;
                   n = n + (float)(*ptr - '0') / del;
                   ptr++;
                }
                *fvar = n;
                v->res = 1;
            }   
            break;
        case 's':
            if(!v->skip) {
                char *svar = va_arg(parameters, char*);
                while(!isspace(*ptr) && *ptr != '\0') {
                    if(v->width > 0) {
                        *svar++ = *ptr++;
                        v->width--;
                    } else if(v->width == -1) {
                        *svar++ = *ptr++;                    
                    } else {
                        break;
                    }            
                    
                }
                *svar = '\0';   
                v->res = 1;
            } else {
                while(!isspace(*ptr) && *ptr != '\0') 
                    ptr++;
            }
            break;
        case 'c':
            if(!v->skip) {
                char *cvar = va_arg(parameters, char*);
                *cvar = *ptr++;
                v->res = 1;
            } else {
                ptr++;
            }   
            break;          
    }
    return ptr;
}

const char *set_signed_int(const char *ptr, va_list parameters, Variable *v, const char *hex_symb) {    
    int *ivar = va_arg(parameters, int*);
    int sign = 1; 
    if(*ptr == '-') {
        sign = -1;
        v->width = v->width > 0 ? v->width - 1 : v->width;
        ptr++;
    }    
    char buff[BUF_SIZE];
    int ind = 0;
    while(ind < BUF_SIZE - 1 && (isdigit(*ptr) || strchr(hex_symb, *ptr))) {
        if(v->width > 0) {
            buff[ind++] = *ptr++; 
            v->width--;
        } else if(v->width == -1) {
            buff[ind++] = *ptr++;            
        } else {
            break;
        }
                           
    }
    buff[ind] = '\0';

    *ivar = (int)strtol(buff, NULL, 0) * sign;        
    v->res = 1;
    return ptr;
}

const char *set_unsigned_int(const char *ptr, va_list parameters, Variable *v, const char *hex_symb) {    
    unsigned int *uvar = va_arg(parameters, unsigned int*);
    
    char buff[BUF_SIZE];
    int ind = 0;
    while(ind < BUF_SIZE - 1 && (isdigit(*ptr) || strchr(hex_symb, *ptr))) {
        if(v->width > 0) {
            buff[ind++] = *ptr++; 
            v->width--;
        } else if(v->width == -1) {
            buff[ind++] = *ptr++;            
        } else {
            break;
        }
                           
    }
    buff[ind] = '\0';


    *uvar = (unsigned int)strtol(buff, NULL, 0);        
    v->res = 1;
    return ptr;
}