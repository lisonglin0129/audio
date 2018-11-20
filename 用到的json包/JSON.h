#ifndef JSON_h
#define JSON_h

#ifdef __cplusplus
extern "C"
{
#endif


#define JSONFalse 0
#define JSONTrue 1
#define JSONNULL 2
#define JSONNumber 3
#define JSONString 4
#define JSONArray 5
#define JSONObject 6
	
#define JSONIsReference 256
#define JSONStringIsConst 512


typedef struct JSON {
	struct JSON *next,*prev;	
	struct JSON *child;		

	int type;				

	char *valuestring;		
	int valueint;				
	double valuedouble;		

	char *string;				
} JSON;

typedef struct JSONHooks {
      void *(*malloc_fn)(size_t sz);
      void (*free_fn)(void *ptr);
} JSONHooks;


extern void JSONInitHooks(JSONHooks* hooks);


extern JSON *JSONParse(const char *value);
extern char  *JSONPrint(JSON *item);
extern char  *JSONPrintUnformatted(JSON *item);
extern char *JSONPrintBuffered(JSON *item,int prebuffer,int fmt);
extern void   JSONDelete(JSON *c);

extern int	  JSONGetArraySize(JSON *array);
extern JSON *JSONGetArrayItem(JSON *array,int item);
extern JSON *JSONGetObjectItem(JSON *object,const char *string);

extern const char *JSONGetErrorPtr(void);
	
extern JSON *JSONCreateNull(void);
extern JSON *JSONCreateTrue(void);
extern JSON *JSONCreateFalse(void);
extern JSON *JSONCreateBool(int b);
extern JSON *JSONCreateNumber(double num);
extern JSON *JSONCreateString(const char *string);
extern JSON *JSONCreateArray(void);
extern JSON *JSONCreateObject(void);

extern JSON *JSONCreateIntArray(const int *numbers,int count);
extern JSON *JSONCreateFloatArray(const float *numbers,int count);
extern JSON *JSONCreateDoubleArray(const double *numbers,int count);
extern JSON *JSONCreateStringArray(const char **strings,int count);

extern void JSONAddItemToArray(JSON *array, JSON *item);
extern void	JSONAddItemToObject(JSON *object,const char *string,JSON *item);
extern void	JSONAddItemToObjectCS(JSON *object,const char *string,JSON *item);	
extern void JSONAddItemReferenceToArray(JSON *array, JSON *item);
extern void	JSONAddItemReferenceToObject(JSON *object,const char *string,JSON *item);


extern JSON *JSONDetachItemFromArray(JSON *array,int which);
extern void   JSONDeleteItemFromArray(JSON *array,int which);
extern JSON *JSONDetachItemFromObject(JSON *object,const char *string);
extern void   JSONDeleteItemFromObject(JSON *object,const char *string);
	
extern void JSONInsertItemInArray(JSON *array,int which,JSON *newitem);	
extern void JSONReplaceItemInArray(JSON *array,int which,JSON *newitem);
extern void JSONReplaceItemInObject(JSON *object,const char *string,JSON *newitem);

extern JSON *JSONDuplicate(JSON *item,int recurse);
extern JSON *JSONParseWithOpts(const char *value,const char **return_parse_end,int require_null_terminated);

extern void JSONMinify(char *json);

#define JSONAddNullToObject(object,name)		JSONAddItemToObject(object, name, JSONCreateNull())
#define JSONAddTrueToObject(object,name)		JSONAddItemToObject(object, name, JSONCreateTrue())
#define JSONAddFalseToObject(object,name)		JSONAddItemToObject(object, name, JSONCreateFalse())
#define JSONAddBoolToObject(object,name,b)	JSONAddItemToObject(object, name, JSONCreateBool(b))
#define JSONAddNumberToObject(object,name,n)	JSONAddItemToObject(object, name, JSONCreateNumber(n))
#define JSONAddStringToObject(object,name,s)	JSONAddItemToObject(object, name, JSONCreateString(s))

#define JSONSetIntValue(object,val)			((object)?(object)->valueint=(object)->valuedouble=(val):(val))
#define JSONSetNumberValue(object,val)		((object)?(object)->valueint=(object)->valuedouble=(val):(val))

#ifdef __cplusplus
}
#endif

#endif
