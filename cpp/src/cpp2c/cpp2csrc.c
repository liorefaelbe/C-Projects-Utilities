/*
	Author: Lior Refael Berkovits
	Reviewed by: Avi
	Date: 25/03/2025
*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* calloc */
#include <stddef.h> /* offsetof */

/*****************************New-Delete**********************************/

void* New(size_t size)
{
    void* obj = malloc(size);

    return (obj);
}

void Delete(void* obj)
{
    free(obj);
}

void* NewArr(size_t size, size_t num)
{
    void* obj = malloc(num * size);

    return (obj);
}

void DeleteArr(void* obj)
{
    free(obj);
}

/*************************PublicTransport-Class***************************/

typedef struct PublicTransport PublicTransport;

void PTCtor(PublicTransport* const this);
void PTDtor(PublicTransport* const this);
void PTCCtor(PublicTransport* const this, const PublicTransport* const other);
PublicTransport* PTClone(PublicTransport* const this);
void PTDisplay(PublicTransport* const this);
void PTPrintCount(void);
int PTGetID(PublicTransport* const this);

static int pt_s_count = 0;

typedef struct
{
    void (*dtor)(PublicTransport* const);
    void (*display)(PublicTransport* const);
    PublicTransport* (*clone)(PublicTransport* const);
}PTVTable;

static const PTVTable pt_vtable = {&PTDtor, &PTDisplay, &PTClone};

struct PublicTransport
{
    const PTVTable* vptr;
    int m_license_plate;
};

/*****************************Constructors********************************/

void PTCtor(PublicTransport* const this)
{
    this->vptr = &pt_vtable;
    ++pt_s_count;
    this->m_license_plate = pt_s_count; 

    printf("PublicTransport::Ctor()%d\n", this->m_license_plate);
}

void PTDtor(PublicTransport* const this)
{
    --pt_s_count; 
    printf("PublicTransport::Dtor()%d\n", this->m_license_plate);
}

void PTCCtor(PublicTransport* const this, const PublicTransport* const other)
{
    (void)other;

    this->vptr = &pt_vtable;
    ++pt_s_count;
    this->m_license_plate = pt_s_count;

    printf("PublicTransport::CCtor() %d\n", this->m_license_plate);
}

/****************************Member-Functions*****************************/

PublicTransport* PTClone(PublicTransport* const this)
{
    PublicTransport* tmp = New(sizeof(PublicTransport));
    PTCCtor(tmp, this);

    return (tmp);
}

void PTDisplay(PublicTransport* const this)
{
    printf("PublicTransport::display(): %d\n", this->m_license_plate);
}

void PTPrintCount(void)
{
    printf("s_count: %d\n", pt_s_count);
}

int PTGetID(PublicTransport* const this)
{
    return (this->m_license_plate);
}

/******************************Minibus-Class******************************/

typedef struct Minibus Minibus;

void MinibusCtor(Minibus* const this);
void MinibusDtor(Minibus* const this);
void MinibusCCtor(Minibus* const this, const Minibus* const other);
Minibus* MinibusClone(Minibus* const this);
void MinibusDisplay(Minibus* const this);
void MinibusWash(Minibus* const this, int minutes);

typedef struct
{
    void (*dtor)(Minibus* const);
    void (*display)(Minibus* const);
    Minibus* (*clone)(Minibus* const);
    void (*wash)(Minibus* const, int);
}MinibusVTable;

static const MinibusVTable minibus_vtable = {&MinibusDtor, &MinibusDisplay, &MinibusClone, &MinibusWash};

struct Minibus
{
    PublicTransport m_pt;
    int m_numSeats;
};

/*****************************Constructors********************************/

void MinibusCtor(Minibus* const this)
{
    PTCtor(&this->m_pt);
    this->m_pt.vptr = (PTVTable*)&minibus_vtable;
    this->m_numSeats = 20; 

    printf("Minibus::Ctor()\n");
}

void MinibusDtor(Minibus* const this)
{
    printf("Minibus::Dtor()\n");

    PTDtor(&this->m_pt);
}

void MinibusCCtor(Minibus* const this, const Minibus* const other)
{
    PTCCtor(&this->m_pt, &other->m_pt);
    this->m_pt.vptr = (PTVTable*)&minibus_vtable;
    this->m_numSeats = other->m_numSeats;

    printf("Minibus::CCtor()\n");
}

/****************************Member-Functions*****************************/

Minibus* MinibusClone(Minibus* const this)
{
    Minibus* tmp = New(sizeof(Minibus));
    MinibusCCtor(tmp, this);

    return (tmp);
}

void MinibusDisplay(Minibus* const this)
{
    printf("Minibus::display() ID:%d num seats:%d\n", PTGetID(&this->m_pt) ,this->m_numSeats);
}
    
void MinibusWash(Minibus* const this,int minutes)
{
    printf("Minibus::wash(%d) ID:%d\n", minutes, PTGetID(&this->m_pt));
}

/****************************ArmyMinibus-Class****************************/

typedef struct ArmyMinibus ArmyMinibus;

void ArmyMinibusCtor(ArmyMinibus* const this);
void ArmyMinibusDtor(ArmyMinibus* const this);
void ArmyMinibusCCtor(ArmyMinibus* const this, const ArmyMinibus* const other);

typedef struct
{
    void (*dtor)(ArmyMinibus* const);
    void (*display)(Minibus* const);
    void (*wash)(Minibus* const, int);
}ArmyMinibusVTable;

static const ArmyMinibusVTable army_minibus_vtable = {&ArmyMinibusDtor, &MinibusDisplay, &MinibusWash};

struct ArmyMinibus
{
    Minibus m_minibus;
};

/*****************************Constructors********************************/

void ArmyMinibusCtor(ArmyMinibus* const this)
{
    MinibusCtor(&this->m_minibus);
    this->m_minibus.m_pt.vptr = (PTVTable*)&army_minibus_vtable;

    printf("ArmyMinibus::Ctor()\n");
}

void ArmyMinibusDtor(ArmyMinibus* const this)
{
    printf("ArmyMinibus::Dtor()\n");

    MinibusDtor(&this->m_minibus);
}

void ArmyMinibusCCtor(ArmyMinibus* const this, const ArmyMinibus* const other)
{
    MinibusCCtor(&this->m_minibus, &other->m_minibus); 
    this->m_minibus.m_pt.vptr = (PTVTable*)&army_minibus_vtable;
    
    printf("ArmyMinibus::CCtor()\n");
}

/******************************Taxi-Class*********************************/

typedef struct Taxi Taxi;

void TaxiCtor(Taxi* const this);
void TaxiDtor(Taxi* const this);
void TaxiCCtor(Taxi* const this, const Taxi* const other);
Taxi* TaxiClone(Taxi* const this);
void TaxiDisplay(Taxi* const this);

typedef struct
{
    void (*dtor)(Taxi* const);
    void (*display)(Taxi* const);
    Taxi* (*clone)(Taxi* const);
}TaxiVTable;

static const TaxiVTable taxi_vtable = {&TaxiDtor, &TaxiDisplay, &TaxiClone};

struct Taxi
{
    PublicTransport m_pt;
};

/*****************************Constructors********************************/

void TaxiCtor(Taxi* const this)
{
    PTCtor(&this->m_pt);
    this->m_pt.vptr = (PTVTable*)&taxi_vtable;

    printf("Taxi::Ctor()\n");
}

void TaxiDtor(Taxi* const this)
{
    printf("Taxi::Dtor()\n");

    PTDtor(&this->m_pt);
}

void TaxiCCtor(Taxi* const this, const Taxi* const other)
{
    PTCCtor(&this->m_pt, &other->m_pt);
    this->m_pt.vptr = (PTVTable*)&taxi_vtable;

    printf("Taxi::CCtor()\n");
}

/****************************Member-Functions*****************************/

Taxi* TaxiClone(Taxi* const this)
{
    Taxi* tmp = New(sizeof(Taxi));
    TaxiCCtor(tmp, this);

    return (tmp);
}

void TaxiDisplay(Taxi* const this)
{
    printf("Taxi::display() ID:%d\n", PTGetID(&this->m_pt));
}

/***************************SpecialTaxi-Class****************************/

typedef struct SpecialTaxi SpecialTaxi;

void SpecialTaxiCtor(SpecialTaxi* const this);
void SpecialTaxiDtor(SpecialTaxi* const this);
void SpecialTaxiCCtor(SpecialTaxi* const this, const SpecialTaxi* const other);
void SpecialTaxiDisplay(SpecialTaxi* const this);

typedef struct
{
    void (*dtor)(SpecialTaxi* const);
    void (*display)(SpecialTaxi* const);
}SpecialTaxiVTable;

static const SpecialTaxiVTable s_taxi_vtable = {&SpecialTaxiDtor, &SpecialTaxiDisplay};

struct SpecialTaxi
{
    Taxi m_taxi;
};

/*****************************Constructors********************************/

void SpecialTaxiCtor(SpecialTaxi* const this)
{
    TaxiCtor(&this->m_taxi);
    this->m_taxi.m_pt.vptr = (PTVTable*)&s_taxi_vtable;

    printf("SpecialTaxi::Ctor()\n");
}

void SpecialTaxiDtor(SpecialTaxi* const this)
{
    printf("SpecialTaxi::Dtor()\n");

    TaxiDtor(&this->m_taxi);
}

void SpecialTaxiCCtor(SpecialTaxi* const this, const SpecialTaxi* const other)
{
    TaxiCCtor(&this->m_taxi, &other->m_taxi);
    this->m_taxi.m_pt.vptr = (PTVTable*)&s_taxi_vtable;

    printf("SpecialTaxi::CCtor()\n");
}

/****************************Member-Functions*****************************/

void SpecialTaxiDisplay(SpecialTaxi* const this)
{
    printf("SpecialTaxi::display() ID:%d\n", PTGetID(&this->m_taxi.m_pt));
}

/***************************PublicConvoy-Class****************************/

typedef struct PublicConvoy PublicConvoy;

void PCCtor(PublicConvoy* const this);
void PCDtor(PublicConvoy* const this);
void PCCCtor(PublicConvoy* const this, const PublicConvoy* const other);
void PCDisplay(PublicConvoy* const this);

typedef struct
{
    void (*dtor)(PublicConvoy* const);
    void (*display)(PublicConvoy* const);
}PublicConvoyVTable;

static const PublicConvoyVTable s_pc_vtable = {&PCDtor, &PCDisplay};

struct PublicConvoy
{
    PublicTransport m_pt;
    PublicTransport* m_pt1;
    PublicTransport* m_pt2;
    Minibus m_m;
    Taxi m_t;
}; 

/*****************************Constructors********************************/

void PCCtor(PublicConvoy* const this)
{
    PTCtor(&this->m_pt);
    this->m_pt.vptr = (PTVTable*)&s_pc_vtable;
    
    this->m_pt1 = New(sizeof(Minibus));
    MinibusCtor((Minibus*)this->m_pt1);
    
    this->m_pt2 = New(sizeof(Taxi));
    TaxiCtor((Taxi*)this->m_pt2);
    
    MinibusCtor(&this->m_m);
    TaxiCtor(&this->m_t);
}

void PCDtor(PublicConvoy* const this)
{
    this->m_pt1->vptr->dtor(this->m_pt1);
    Delete(this->m_pt1);
    
    this->m_pt2->vptr->dtor(this->m_pt2);
    Delete(this->m_pt2);
    
    TaxiDtor(&this->m_t);
    MinibusDtor(&this->m_m);
    PTDtor(&this->m_pt);
}

void PCCCtor(PublicConvoy* const this, const PublicConvoy* const other)
{
    PTCCtor(&this->m_pt, &other->m_pt);
    this->m_pt.vptr = (PTVTable*)&s_pc_vtable;
    
    this->m_pt1 = other->m_pt1->vptr->clone(other->m_pt1);
    this->m_pt2 = other->m_pt2->vptr->clone(other->m_pt2);
    
    MinibusCCtor(&this->m_m, &other->m_m);
    TaxiCCtor(&this->m_t, &other->m_t);
}

/****************************Member-Functions*****************************/

void PCDisplay(PublicConvoy* const this)
{
    this->m_pt1->vptr->display(this->m_pt1);
    this->m_pt2->vptr->display(this->m_pt2);

    MinibusDisplay(&this->m_m);
    TaxiDisplay(&this->m_t);
}

/****************************Template-Class*******************************/

#define TEMPLATE_MAX(T) T Max_##T(T a, T b) { return ( a > b ? a : b); }

TEMPLATE_MAX(int)

/*****************************Free-Functions******************************/

void print_info_pt_const_p(PublicTransport* const a)
{
    a->vptr->display(a);
}

void print_info_void(void)
{
    PTPrintCount();
}

void print_info_minbus_const_p(Minibus* const m)
{
    ((MinibusVTable*)m->m_pt.vptr)->wash(m, 3);
}

PublicTransport print_info_ret(PublicTransport* ret_add, int i)
{
    (void)i;

    Minibus ret;
    MinibusCtor(&ret);

    printf("print_info(int i)\n");

    MinibusDisplay(&ret);

    PTCCtor(ret_add, &ret.m_pt);

    MinibusDtor(&ret);

    return (*ret_add);
}

void taxi_display(Taxi s)
{
    TaxiDisplay(&s);
}

/********************************Main*************************************/

int main()
{
    Minibus m;
    MinibusCtor(&m);

    print_info_minbus_const_p(&m);

    PublicTransport tmp = print_info_ret(&tmp, 3);
    PTDisplay(&tmp);
    PTDtor(&tmp);

/*************************************************************************/

    PublicTransport* array[3] = {0};

    array[0] = New(sizeof(Minibus));
    MinibusCtor((Minibus*)array[0]);

    array[1] = New(sizeof(Taxi));
    TaxiCtor((Taxi*)array[1]);

    array[2] = New(sizeof(Minibus));
    MinibusCtor((Minibus*)array[2]);

    for(int i = 0; i < 3; ++i) 
    {
        array[i]->vptr->display(array[i]);
    }

    for (int i = 0; i < 3; ++i) 
    {
        array[i]->vptr->dtor(array[i]);
        Delete(array[i]);
    }

/*************************************************************************/

    PublicTransport arr2[3] = {0};

    Minibus m1;
    Taxi t1;

    MinibusCtor(&m1);
    PTCCtor(&arr2[0], &m1.m_pt);

    TaxiCtor(&t1);
    PTCCtor(&arr2[1], &t1.m_pt);

    PTCtor(&arr2[2]);

    TaxiDtor(&t1);
    MinibusDtor(&m1);

    for (int i = 0; i < 3; ++i) 
    {
        PTDisplay(&arr2[i]);
    }
    print_info_pt_const_p(&arr2[0]);

/*************************************************************************/

    PTPrintCount();

    Minibus m2;
    MinibusCtor(&m2);

    PTPrintCount();

    Minibus arr3[4] = {0};

    for(int i = 0; i < 4; ++i)
    {
        MinibusCtor(&arr3[i]);
    }

    Taxi* arr4 = NewArr(sizeof(Taxi),4);

    for(int i = 0; i < 4; ++i)
    {
        TaxiCtor(&arr4[i]);
    }

    for(int i = 3; i >= 0; --i)
    {
        TaxiDtor(&arr4[i]);
    }

    DeleteArr(arr4);

/*************************************************************************/

    printf("%d\n", Max_int(1, 2));
    printf("%d\n", Max_int(1, 2.0f));

/*************************************************************************/

    SpecialTaxi st;
    Taxi tmp_t;

    SpecialTaxiCtor(&st);
    TaxiCCtor(&tmp_t, &st.m_taxi);
    taxi_display(tmp_t);
    TaxiDtor(&tmp_t);

/*************************************************************************/

    PublicConvoy* ts1 = New(sizeof(PublicConvoy));
    PCCtor(ts1);

    PublicConvoy* ts2 = New(sizeof(PublicConvoy));
    PCCCtor(ts2, ts1);

    ((PublicConvoyVTable*)(ts1->m_pt.vptr))->display(ts1);   // display();
    ((PublicConvoyVTable*)(ts2->m_pt.vptr))->display(ts2);   // ts2->display();

    PCDtor(ts1);
    Delete(ts1);
    
    ((PublicConvoyVTable*)(ts2->m_pt.vptr))->display(ts2);   // ts2->display();

    PCDtor(ts2);
    Delete(ts2);

/*************************************************************************/

    ArmyMinibus* army_minibus = NULL;
    army_minibus = New(sizeof(ArmyMinibus));

    ArmyMinibusCtor(army_minibus);
    
    ((ArmyMinibusVTable*)(army_minibus->m_minibus.m_pt.vptr))->display(&army_minibus->m_minibus);
    ((ArmyMinibusVTable*)(army_minibus->m_minibus.m_pt.vptr))->wash(&army_minibus->m_minibus, 5);
    ((ArmyMinibusVTable*)(army_minibus->m_minibus.m_pt.vptr))->dtor(army_minibus);

    Delete(army_minibus);

/*************************************************************************/

    SpecialTaxiDtor(&st);

    for(int i = 3; i >= 0; --i)
    {
        MinibusDtor(&arr3[i]);
    }

    MinibusDtor(&m2);

    for(int i = 2; i >= 0; --i)
    {
        PTDtor(&arr2[i]);
    }
    
    MinibusDtor(&m);

    return (0);
}