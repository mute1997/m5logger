typedef struct feature {
  void(*fn_init)(void);
  void(*fn_finish)(void);
  void(*fn_main)(void);
} feature_t;

void show_button_labels(char*, char*, char*);
void show_title(char*);
