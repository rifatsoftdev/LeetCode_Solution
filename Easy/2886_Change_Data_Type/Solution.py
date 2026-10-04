import pandas as pd


def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype('int64')

    return students


if __name__ == "__main__":
    pass

    # test cases 1
    # test cases 2
    
    