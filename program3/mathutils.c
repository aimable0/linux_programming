#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* variance(PyObject *self, PyObject *args)
{
    PyObject *list;

    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;

    Py_ssize_t n = PyList_Size(list);

    double mean = 0.0;

    for (Py_ssize_t i = 0; i < n; i++)
    {
        PyObject *item = PyList_GetItem(list, i);
        mean += PyFloat_AsDouble(item);
    }

    mean /= n;

    double var = 0.0;

    for (Py_ssize_t i = 0; i < n; i++)
    {
        PyObject *item = PyList_GetItem(list, i);
        double x = PyFloat_AsDouble(item);
        var += (x - mean) * (x - mean);
    }

    var /= n;

    return PyFloat_FromDouble(var);
}


static PyMethodDef MathMethods[] = {
    {"variance", variance, METH_VARARGS, "Compute variance of a list"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef mathmodule = {
    PyModuleDef_HEAD_INIT,
    "mathutils",
    NULL,
    -1,
    MathMethods
};


PyMODINIT_FUNC PyInit_mathutils(void)
{
    return PyModule_Create(&mathmodule);
}

