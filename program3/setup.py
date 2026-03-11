from setuptools import setup, Extension

module = Extension(
    "mathutils",
    sources=["mathutils.c"]
)

setup(
    name="mathutils",
    version="1.0",
    description="Fast math utilities using C extension",
    ext_modules=[module]
)

