
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
#include "natron_python_pyoverlayparamdesc_wrapper.h"

// inner classes

// Extra includes


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


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_PyOverlayParamDesc_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::PyOverlayParamDesc >()))
        return -1;

    ::Natron::Python::PyOverlayParamDesc* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyOverlayParamDesc()
            cptr = new ::Natron::Python::PyOverlayParamDesc();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::PyOverlayParamDesc >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyMethodDef Sbk_Natron_Python_PyOverlayParamDesc_methods[] = {

    {nullptr, nullptr} // Sentinel
};

static PyObject* Sbk_Natron_Python_PyOverlayParamDesc_get_type(PyObject* self, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppSelf->type);
    return pyOut;
}
static int Sbk_Natron_Python_PyOverlayParamDesc_set_type(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'type' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'type', 'QString' or convertible type expected");
        return -1;
    }

    ::QString& cppOut_ptr = cppSelf->type;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_Python_PyOverlayParamDesc_get_nDims(PyObject* self, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    int cppOut_local = cppSelf->nDims;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_Python_PyOverlayParamDesc_set_nDims(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'nDims' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'nDims', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->nDims;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->nDims = cppOut_local;

    return 0;
}

static PyObject* Sbk_Natron_Python_PyOverlayParamDesc_get_optional(PyObject* self, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    bool cppOut_local = cppSelf->optional;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_Python_PyOverlayParamDesc_set_optional(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::PyOverlayParamDesc* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::PyOverlayParamDesc *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'optional' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'optional', 'bool' or convertible type expected");
        return -1;
    }

    bool cppOut_local = cppSelf->optional;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->optional = cppOut_local;

    return 0;
}

// Getters and Setters for PyOverlayParamDesc
static PyGetSetDef Sbk_Natron_Python_PyOverlayParamDesc_getsetlist[] = {
    {const_cast<char*>("type"), Sbk_Natron_Python_PyOverlayParamDesc_get_type, Sbk_Natron_Python_PyOverlayParamDesc_set_type},
    {const_cast<char*>("nDims"), Sbk_Natron_Python_PyOverlayParamDesc_get_nDims, Sbk_Natron_Python_PyOverlayParamDesc_set_nDims},
    {const_cast<char*>("optional"), Sbk_Natron_Python_PyOverlayParamDesc_get_optional, Sbk_Natron_Python_PyOverlayParamDesc_set_optional},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyOverlayParamDesc_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyOverlayParamDesc_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyOverlayParamDesc_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyOverlayParamDesc_TypeF(void)
{
    return _Sbk_Natron_Python_PyOverlayParamDesc_Type;
}

static PyType_Slot Sbk_Natron_Python_PyOverlayParamDesc_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayParamDesc_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayParamDesc_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayParamDesc_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayParamDesc_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayParamDesc_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyOverlayParamDesc_spec = {
    "NatronEngine.Natron.Python.PyOverlayParamDesc",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyOverlayParamDesc_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyOverlayParamDesc_PythonToCpp_PyOverlayParamDesc_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyOverlayParamDesc_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyOverlayParamDesc_PythonToCpp_PyOverlayParamDesc_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyOverlayParamDesc_TypeF())))
        return PyOverlayParamDesc_PythonToCpp_PyOverlayParamDesc_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyOverlayParamDesc_PTR_CppToPython_PyOverlayParamDesc(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyOverlayParamDesc *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyOverlayParamDesc_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyOverlayParamDesc_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PyOverlayParamDesc()",
    nullptr}; // Sentinel

void init_Natron_Python_PyOverlayParamDesc(PyObject* module)
{
    _Sbk_Natron_Python_PyOverlayParamDesc_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyOverlayParamDesc",
        "Natron::Python::PyOverlayParamDesc*",
        &Sbk_Natron_Python_PyOverlayParamDesc_spec,
        Natron_Python_PyOverlayParamDesc_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyOverlayParamDesc >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyOverlayParamDesc_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyOverlayParamDesc_TypeF(),
        PyOverlayParamDesc_PythonToCpp_PyOverlayParamDesc_PTR,
        is_PyOverlayParamDesc_PythonToCpp_PyOverlayParamDesc_PTR_Convertible,
        PyOverlayParamDesc_PTR_CppToPython_PyOverlayParamDesc);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayParamDesc");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayParamDesc*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayParamDesc&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayParamDesc");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayParamDesc*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayParamDesc&");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayParamDesc");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayParamDesc*");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayParamDesc&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyOverlayParamDesc).name());



}
