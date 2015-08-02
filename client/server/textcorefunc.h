#ifndef TEXTCOREFUNC_H
#define TEXTCOREFUNC_H
#include "QString"
#include <QDebug>
/*!
 * \brief The editType enum - типы редактирования текста
 */
enum editType{
    INSERT,
    BACKSPACE,
    DELETE
};
/*!
 * \brief updateText - Обновить текст
 * \param t - Исходный текст
 * \param type - Тип изменений в тексте
 * \param start - Начальная позиция курсора в тексте
 * \param end - Конечна позиция курсора в тексте
 * \param diff - Добавленный текст
 * \return - Новый текст
 */
QString updateText(const QString &t, editType type, int start, int end, int anchor, QString diff);
/*!
 * \brief getDiff - Получить различия текущего и последнего синхронизированного текста
 * \param t - Текст текущий
 * \param start - Начальная позиция курсора в тексте
 * \param end - Конечна позиция курсора в тексте
 * \param type - Тип изменений в тексте
 * \return Добавленный текст
 */
QString getDiff(QString &t, int start, int end, int anchor, editType &type);
#endif // TEXTCOREFUNC_H
