
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <qapp_macro.h>
#include <typeinfo>

// module include
#include "natronengine_python.h"

// main header
#include "natron_python_int3dparam_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>
#include <PyItemsTable.h>
#include <PyNode.h>
#include <PyParameter.h>


#include <cctype>
#include <cstring>

QT_WARNING_DISABLE_DEPRECATED
using namespace Natron;



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}

// Native ---------------------------------------------------------

void Int3DParamWrapper::pysideInitQtMetaTypes()
{
}

Int3DParamWrapper::~Int3DParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_Int3DParamFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    Int3DParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<Int3DParamWrapper *>(reinterpret_cast< ::Natron::Python::Int3DParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.get(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: IntParam::get(QString)const
    // 1: IntParam::get(double,QString)const
    if (numArgs == 0) {
        overloadId = 0; // get(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // get(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // get(double,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // get(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_Int3DParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get(const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_get_TypeError;
                }
            }
            ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(QString)const
                Natron::Python::Int3DTuple* cppResult = new Natron::Python::Int3DTuple(const_cast<const ::Int3DParamWrapper*>(cppSelf)->get(cppArg0));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
        case 1: // get(double frame, const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_get_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // get(double,QString)const
                Natron::Python::Int3DTuple* cppResult = new Natron::Python::Int3DTuple(const_cast<const ::Int3DParamWrapper*>(cppSelf)->get(cppArg0, cppArg1));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_Int3DParamFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Int3DParam.get");
        return {};
}

static PyObject* Sbk_Natron_Python_Int3DParamFunc_set(PyObject* self, PyObject* args, PyObject* kwds)
{
    Int3DParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<Int3DParamWrapper *>(reinterpret_cast< ::Natron::Python::Int3DParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.set(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.set(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:set", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Int3DParam::set(int,int,int,QString)
    // 1: Int2DParam::set(int,int,QString)
    // 2: IntParam::set(int,QString)
    // 3: Int3DParam::set(int,int,int,double,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 2; // set(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 2; // set(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // set(int,int,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 1; // set(int,int,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // set(int,int,int,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 3; // set(int,int,int,double,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 3; // set(int,int,int,double,QString)
                    }
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    overloadId = 0; // set(int,int,int,QString)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_Int3DParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(int x, int y, int z, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            ::QString cppArg3 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // set(int,int,int,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
        case 1: // set(int x, int y, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int2DParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(int,int,QString)
                reinterpret_cast<Natron::Python::Int2DParam *>(cppSelf)->set(cppArg0, cppArg1, cppArg2);
            }
            break;
        }
        case 2: // set(int x, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.IntParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(int,QString)
                reinterpret_cast<Natron::Python::IntParam *>(cppSelf)->set(cppArg0, cppArg1);
            }
            break;
        }
        case 3: // set(int x, int y, int z, double frame, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Int3DParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                        goto Sbk_Natron_Python_Int3DParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // set(int,int,int,double,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_Int3DParamFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Int3DParam.set");
        return {};
}

static PyMethodDef Sbk_Natron_Python_Int3DParam_methods[] = {
    {"get", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_Int3DParamFunc_get), METH_VARARGS|METH_KEYWORDS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_Int3DParamFunc_set), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_Int3DParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_Int3DParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Int3DParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_Int3DParam_TypeF(void)
{
    return _Sbk_Natron_Python_Int3DParam_Type;
}

static PyType_Slot Sbk_Natron_Python_Int3DParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_Int3DParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_Int3DParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_Int3DParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_Int3DParam_spec = {
    "NatronEngine.Natron.Python.Int3DParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_Int3DParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_Int3DParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::Int3DParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Int3DParam_PythonToCpp_Int3DParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_Int3DParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Int3DParam_PythonToCpp_Int3DParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Int3DParam_TypeF())))
        return Int3DParam_PythonToCpp_Int3DParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Int3DParam_PTR_CppToPython_Int3DParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::Int3DParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_Int3DParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_Int3DParam_SignatureStrings[] = {
    "1:NatronEngine.Natron.Python.Int3DParam.get(view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.Python.Int3DTuple",
    "0:NatronEngine.Natron.Python.Int3DParam.get(frame:double,view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.Python.Int3DTuple",
    "3:NatronEngine.Natron.Python.Int3DParam.set(x:int,y:int,z:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "2:NatronEngine.Natron.Python.Int3DParam.set(x:int,y:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "1:NatronEngine.Natron.Python.Int3DParam.set(x:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "0:NatronEngine.Natron.Python.Int3DParam.set(x:int,y:int,z:int,frame:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    nullptr}; // Sentinel

void init_Natron_Python_Int3DParam(PyObject* module)
{
    _Sbk_Natron_Python_Int3DParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Int3DParam",
        "Natron::Python::Int3DParam*",
        &Sbk_Natron_Python_Int3DParam_spec,
        Natron_Python_Int3DParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::Int3DParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT2DPARAM_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Int3DParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_Int3DParam_TypeF(),
        Int3DParam_PythonToCpp_Int3DParam_PTR,
        is_Int3DParam_PythonToCpp_Int3DParam_PTR_Convertible,
        Int3DParam_PTR_CppToPython_Int3DParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Int3DParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Int3DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Int3DParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::Int3DParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::Int3DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::Int3DParam&");
    Shiboken::Conversions::registerConverterName(converter, "Int3DParam");
    Shiboken::Conversions::registerConverterName(converter, "Int3DParam*");
    Shiboken::Conversions::registerConverterName(converter, "Int3DParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::Int3DParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::Int3DParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_Int3DParam_TypeF(), &Sbk_Natron_Python_Int3DParam_typeDiscovery);


    Int3DParamWrapper::pysideInitQtMetaTypes();
}
