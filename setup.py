import pybind11
from setuptools import Extension, setup

ext_modules = [
    Extension(
        "hash_table_py",
        sources=[
            "Hash Structure/Source/hash_table.cpp",
            "Hash Structure/Source/hash_table_binding.cpp",
        ],
        include_dirs=[
            pybind11.get_include(),
            "Hash Structure/Header",
        ],
        language="c++",
        extra_compile_args=["-std=c++17"],
    ),
]

setup(
    name="hash_table_py",
    version="0.1",
    ext_modules=ext_modules,
)
