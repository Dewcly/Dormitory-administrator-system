#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <ctype.h>
#include <time.h>

#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#define SCR_ROW 25             /*��Ļ����*/
#define SCR_COL 80             /*��Ļ����*/

/**
 *�ɷ���Ϣ�����ṹ
 */
typedef struct charge_node {
    char stu_id[12];           /**< ѧ��*/
    char name[10];             /**< ����*/
    char date[12];             /**< �ɷ�����*/
    float sum;                 /**< �ɷѽ��*/
    char payee[10];            /**< �շ���*/
    char notes[5];             /**< ��ע*/
    struct charge_node *next;  /**< ָ����һ����ָ��*/
} CHARGE_NODE;

/**
 *ѧ��������Ϣ�����ṹ
 */
typedef struct stu_node {
    char stu_id[12];            /**< ѧ��*/
    char name[10];              /**< ����*/
    char sex;                   /**< �Ա�*/
    char birthday[12];          /**< ��������*/
    char type[3];               /**< ѧ�����*/
    char term;                  /**< ѧ��*/
    char enroll_date[8];        /**< ��ѧ����*/
    char class_id[10];          /**< �༶*/
    char dorm_id[5];            /**< ����¥��*/
    char room[5];               /**< �����*/
    char tel[20];               /**< ��ϵ�绰*/
    struct charge_node *cnext;  /**< ָ��ɷ���Ϣ֧����ָ��*/
    struct stu_node *next;      /**< ָ����һ����ָ��*/
} STU_NODE;

/**
 *����¥��Ϣ�����ṹ
 */
typedef struct dorm_node {
    char dorm_id[5];         /**< ����¥��*/
    char name[10];           /**< ����*/
    char tel[20];            /**< ��ϵ�绰*/
    short room_amount;       /**< ������Ŀ*/
    short bed_amount;        /**< ��λ��Ŀ*/
    float fee;               /**< ÿ��λÿ��ס�޷�*/
    struct stu_node *snext;  /**< ָ��ѧ��������Ϣ֧����ָ��*/
    struct dorm_node *next;  /**< ָ����һ����ָ��*/
} DORM_NODE;

/**
 *����¥��ס��ͳ����Ϣ�����ṹ
 */
typedef struct use_rate_node {
    char dorm_id[5];            	/**< ����¥��*/
    unsigned short total_num;     	/**< ��סѧ����*/
    unsigned short used_num;     	/**< ��סѧ����*/
    unsigned short free_num;     	/**< �մ�λ��*/
    float use_rate;              	/**< ��ס��*/
    struct use_rate_node *next;   	/**< ָ����һ����ָ��*/
} USE_RATE_NODE;

/**
 *��סѧ������ͳ����Ϣ�����ṹ
 */
typedef struct stu_type_node {
    char grade[5];               	/**< �꼶*/
    unsigned short school_boy1;   	/**< ��ר������*/
    unsigned short school_girl1;   	/**< Ůר������*/
    unsigned short school_boy2;   	/**< �б�������*/
    unsigned short school_girl2;   	/**< Ů��������*/
    unsigned short school_boy3;   	/**< ��˶ʿ����*/
    unsigned short school_girl3;   	/**< Ů˶ʿ����*/
    unsigned short school_boy4;   	/**< �в�ʿ����*/
    unsigned short school_girl4;   	/**< Ů��ʿ����*/
    unsigned short school_boy5;   	/**< ����������*/
    unsigned short school_girl5;   	/**< ����Ů����*/
    struct stu_type_node *next;    	/**< ָ����һ����ָ��*/
} STU_TYPE_NODE;

/**
 *����¥���ס�޷�����ͳ����Ϣ�����ṹ
 */
typedef struct income_node {
    char dorm_id[5];            	/**< ����¥��*/
    float year1_income;          	/**< ���1����*/
    float year2_income;          	/**< ���2����*/
    float year3_income;          	/**< ���3����*/
    float year4_income;          	/**< ���4����*/
    struct income_node *next;     	/**< ָ����һ����ָ��*/
} INCOME_NODE;

/**
 *��סѧ��Ƿ��ͳ����Ϣ�����ṹ
 */
typedef struct uncharge_node {
    char stu_id[12];             	/**< ѧ��*/
    char name[10];             	    /**< ����*/
    char dorm_id[5];            	/**< ����¥��*/
    char room_num[5];               /**< �����*/
    float amount;               	/**< Ƿ�ɽ��*/
    struct uncharge_node *next;   	/**< ָ����һ����ָ��*/
} UNCHARGE_NODE;

/**
 *��Ļ������Ϣ�������ṹ
 */
typedef struct layer_node {
    char LayerNo;            /**< �������ڲ���*/
    SMALL_RECT rcArea;       /**< ����������������*/
    CHAR_INFO *pContent;     /**< �������������ַ���Ԫԭ��Ϣ�洢������*/
    char *pScrAtt;           /**< �������������ַ���Ԫԭ����ֵ�洢������*/
    struct layer_node *next; /**< ָ����һ����ָ��*/
} LAYER_NODE;

/**
 *��ǩ���ṹ
 */
typedef struct labe1_bundle {
    char **ppLabel;        /**< ��ǩ�ַ��������׵�ַ*/
    COORD *pLoc;           /**< ��ǩ��λ�����׵�ַ*/
    int num;               /**< ��ǩ����*/
} LABEL_BUNDLE;

/**
 *�����ṹ
 */
typedef struct hot_area {
    SMALL_RECT *pArea;     /**< ������λ�����׵�ַ*/
    char *pSort;           /**< �������(�������ı���ѡ���)�����׵�ַ*/
    char *pTag;            /**< ������������׵�ַ*/
    int num;               /**< ��������*/
} HOT_AREA;

LAYER_NODE *gp_top_layer = NULL;               /*����������Ϣ����ͷ*/
DORM_NODE *gp_head = NULL;                     /*����ͷָ��*/

char *gp_sys_name = "ѧ��ס����Ϣ����ϵͳ";    /*ϵͳ����*/
char *gp_stu_info_filename = "stu.dat";        /*ѧ��������Ϣ�����ļ�*/
char *gp_charge_info_filename = "charge.dat";  /*ס�޽ɷ���Ϣ�����ļ�*/
char *gp_dorm_info_filename = "Dorm.dat";      /*����¥��Ϣ�����ļ�*/
char *gp_sex_code_filename = "sex.dat";        /*�Ա���������ļ�*/
char *gp_type_code_filename = "type.dat";      /*ѧ�������������ļ�*/

char *ga_main_menu[] = {"�ļ�(F)",             /*ϵͳ���˵���*/
    	                "����ά��(M)",
                        "���ݲ�ѯ(Q)",
                        "����ͳ��(S)",
                        "����(H)"
                       };

char *ga_sub_menu[] = {"[S] ���ݱ���",          /*ϵͳ�Ӳ˵���*/
                       "[B] ���ݱ���",
                       "[R] ���ݻָ�",
                       "[X] �˳�    Alt+X",
                       "[S] �Ա����",
                       "[T] ѧ��������",
                       "",           /*�մ������ڵ����˵��зָ��Ӳ˵����ͬ*/
                       "[D] ����¥��Ϣ",
                       "[P] ѧ��������Ϣ",
                       "[C] ס�޽ɷ���Ϣ",
                       "[S] �Ա����",
                       "[T] ѧ��������",
                       "",
                       "[D] ����¥��Ϣ",
                       "[P] ѧ��������Ϣ",
                       "[C] ס�޽ɷ���Ϣ",
                       "[I] ����¥��ס��",
                       "[T] ��סѧ������",
                       "[C] ס�޷ѽ������",
                       "[U] ס�޷�Ƿ�����",
                       "[T] ��������",
                       "",
                       "[A] ����..."
                      };

int ga_sub_menu_count[] = {4, 6, 6, 4, 3};  /*�����˵������Ӳ˵��ĸ���*/
int gi_sel_menu = 1;                        /*��ѡ�е����˵����,��ʼΪ1*/
int gi_sel_sub_menu = 0;                    /*��ѡ�е��Ӳ˵����,��ʼΪ0,��ʾδѡ��*/

CHAR_INFO *gp_buff_menubar_info = NULL;     /*��Ų˵�����Ļ���ַ���Ϣ�Ļ�����*/
CHAR_INFO *gp_buff_stateBar_info = NULL;    /*���״̬����Ļ���ַ���Ϣ�Ļ�����*/

char *gp_scr_att = NULL;    /*�����Ļ���ַ���Ԫ����ֵ�Ļ�����*/
char *gp_sex_code = NULL;   /*����Ա���������ݻ�����*/
char *gp_type_code = NULL;  /*���ѧ�������������ݻ�����*/
char gc_sys_state = '\0';   /*��������ϵͳ״̬���ַ�*/

unsigned long gul_sex_code_len = 0;    /*�Ա�������*/
unsigned long gul_type_code_len = 0;   /*ѧ�����������*/

HANDLE gh_std_out;          /*��׼����豸���*/
HANDLE gh_std_in;           /*��׼�����豸���*/

int LoadCode(char *filename, char **ppbuffer);  /*��������*/
int CreatList(DORM_NODE **pphead);              /*���������ʼ��*/
void InitInterface(void);                 /*ϵͳ�����ʼ��*/
void ClearScreen(void);                         /*����*/
void ShowMenu(void);                            /*��ʾ�˵���*/
void PopMenu(int num);                          /*��ʾ�����˵�*/
void PopPrompt(int num);                        /*��ʾ��������*/
void PopUp(SMALL_RECT *, WORD, LABEL_BUNDLE *, HOT_AREA *);  /*����������Ļ��Ϣά��*/
void PopOff(void);                              /*�رն��㵯������*/
void DrawBox(SMALL_RECT *parea);                /*���Ʊ߿�*/
void LocSubMenu(int num, SMALL_RECT *parea);    /*���˵������˵���λ*/
void ShowState(void);                           /*��ʾ״̬��*/
void TagMainMenu(int num);                      /*��Ǳ�ѡ�е����˵���*/
void TagSubMenu(int num);                       /*��Ǳ�ѡ�е��Ӳ˵���*/
int DealConInput(HOT_AREA *phot_area, int *pihot_num);  /*����̨���봦��*/
void SetHotPoint(HOT_AREA *phot_area, int hot_num);     /*��������*/
void RunSys(DORM_NODE **pphd);                  /*ϵͳ����ģ���ѡ�������*/
BOOL ExeFunction(int main_menu_num, int sub_menu_num);  /*����ģ��ĵ���*/
void CloseSys(DORM_NODE *phd);                  /*�˳�ϵͳ*/
BOOL ShowModule(char **pString, int n);

BOOL LoadData(void);           /*���ݼ���*/
BOOL SaveData(void);           /*��������*/
BOOL BackupData(void);         /*��������*/
BOOL RestoreData(void);        /*�ָ�����*/
BOOL ExitSys(void);            /*�˳�ϵͳ*/
BOOL HelpTopic(void);          /*��������*/
BOOL AboutDorm(void);          /*����ϵͳ*/

BOOL MaintainSexCode(void);    /*ά���Ա����*/
BOOL MaintainTypeCode(void);   /*ά��ѧ��������*/
BOOL MaintainDormInfo(void);   /*ά������¥��Ϣ*/
BOOL MaintainStuInfo(void);    /*ά��ѧ��������Ϣ*/
BOOL MaintainChargeInfo(void); /*ά��ѧ���ɷ���Ϣ*/

BOOL QuerySexCode(void);       /*��ѯ�Ա����*/
BOOL QueryTypeCode(void);      /*��ѯѧ��������*/
BOOL QueryDormInfo(void);      /*��ѯ����¥��Ϣ*/
BOOL QueryStuInfo(void);       /*��ѯѧ��������Ϣ*/
BOOL QueryChargeInfo(void);    /*��ѯ�ɷ���Ϣ*/

BOOL StatUsedRate(void);       /*ͳ����ס��*/
BOOL StatStuType(void);        /*ѧ������ͳ��*/
BOOL StatCharge(void);         /*ѧ���ɷ���Ϣͳ��*/
BOOL StatUncharge(void);       /*ѧ��Ƿ����Ϣͳ��*/

BOOL InsertChargeNode(DORM_NODE *phd, CHARGE_NODE *pcharge_node);/*����ɷ���Ϣ���*/
BOOL DelChargeNode(DORM_NODE *phd, char *stu_id, char *date);/*ɾ���ɷ���Ϣ���*/
BOOL ModifChargeNode(DORM_NODE *phd, char *stu_id, char *date, CHARGE_NODE *pcharge_node);/*�޸Ľɷ���Ϣ���*/
STU_NODE *SeekStuNode(DORM_NODE *phd, char *stu_id);  /*����ѧ��������Ϣ���*/
CHARGE_NODE *SeekChargeNode(DORM_NODE *phd, char *stu_id, char *date);/*���ҽɷ���Ϣ���*/
STU_NODE *SeekStuNodeM (DORM_NODE *phd, int cond_num, ...);/*ģ����ѯѧ����Ϣ���*/
BOOL JudgeStuNodeItem(STU_NODE *pstu_node, char *pcond);/*�ж�ѧ����Ϣ�������Ƿ������ѯ����*/
BOOL MatchString(char *string_item, char *pcond);/*�ַ������ѯ�����Ƿ�����ָ���������ϵ*/
BOOL MatchChar(char char_item, char *pcond);/*�ַ����ѯ�����Ƿ�����ָ���������ϵ*/
UNCHARGE_NODE *StatUnchargeInfo(DORM_NODE *phd);        /*ѧ��Ƿ����Ϣͳ��*/
void SortUnchargeInfo(UNCHARGE_NODE *puncharge_hd);     /*Ƿ����Ϣ������*/
BOOL SaveSysData(DORM_NODE *phd);                       /*����ϵͳ����*/
BOOL BackupSysData(DORM_NODE *phd, char *filename);     /*����ϵͳ����*/
BOOL RestoreSysData(DORM_NODE **pphd, char *filename);  /*�ָ�ϵͳ����*/

#endif /**< TYPE_H_INCLUDED*/
