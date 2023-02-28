import argparse
import datetime
import os


def checkSuffix(suffix, file):
    fileCopy = file
    fileCopy = fileCopy.split('.')
    fileCopy = fileCopy[0]
    cutBegin = len(fileCopy) - len(suffix)
    cutEnd = len(fileCopy)

    fileCopy = fileCopy[cutBegin:cutEnd]

    return fileCopy == suffix


def writeData(suffix, outFile):
    outFile = os.path.abspath(outFile)
    fileList = os.listdir()
    blockSize = 4096

    with open(outFile, 'w') as fileOut:
        fileSize = 0

        for file in fileList:
            file = os.path.abspath(file)

            if os.path.isfile(file) and not os.access(file, os.X_OK):
                fileSize = os.stat(file).st_size

                if checkSuffix(suffix, file) and fileSize % blockSize == 0:
                    fileOut.write(f'{file} {fileSize}\n')


def main():
    now = datetime.datetime.now()
    nowTime = now.time()

    parser = argparse.ArgumentParser()
    parser.add_argument("-sf", "--suffix", type=str, help='End of file name', required=True)
    parser.add_argument("-o", "--outFile", type=str, help='Path to output file', default=f'{nowTime}.txt')

    args = parser.parse_args()

    suffix = args.suffix
    outFile = args.outFile

    writeData(suffix, outFile)


if __name__ == "__main__":
    main()
